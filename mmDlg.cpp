
// mmDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mm.h"
#include "mmDlg.h"
#include "afxdialogex.h"
#include "./json/json.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


void CmmDlg::switch2play()
{
	if(m_playing = !m_playing){
		CRect rect;
		GetDlgItem(IDC_PLAYER)->GetWindowRect(&rect);
		// ScreenToClient(&rect);
		m_playerDlg.MoveWindow(rect);
		m_playerDlg.ShowWindow(SW_SHOW);
	} else {
		m_playerDlg.ShowWindow(SW_HIDE);
	}
}

void CmmDlg::start_moving()
{
	m_moving = true;
	GetWindowRect(&m_rc);
	GetCursorPos(&m_pt);
	SetCapture();
}

void CmmDlg::stop_moving()
{
	m_moving = false;
	ReleaseCapture();
}

void CmmDlg::moving()
{
	if (m_moving)
	{
		CPoint pt;
		CRect rc;
		GetCursorPos(&pt);
		rc = m_rc - m_pt + pt;
		MoveWindow(&rc);
		if(m_playing){
			CRect rect;
			GetDlgItem(IDC_PLAYER)->GetWindowRect(&rect);
			// ScreenToClient(&rect);
			m_playerDlg.MoveWindow(rect);
		}
	}
}

void CmmDlg::callcpp(const VARIANT& type, const VARIANT& msg)
{
	CComVariant var_type(type), var_msg(msg);
	var_type.ChangeType(VT_BSTR);
	var_msg.ChangeType(VT_BSTR);
// 	USES_CONVERSION;
// 	CString strType(OLE2T(var_type.bstrVal));
	CString strType(var_type.bstrVal);
	CString strMsg(var_msg.bstrVal);
	if(strType.CompareNoCase(L"switch") == 0){
		switch2play();
	} else if(strType.CompareNoCase(L"exit") == 0){
		OnOK();
	} else if(strType.CompareNoCase(L"miximum") == 0){
		ShowWindow(SW_MINIMIZE);
	}
	// AfxMessageBox(strMsg);

	// MessageBox(L"hello!", L"title", MB_OK);
	// IHTMLDocument2* pDocument;
	// IHTMLWindow2* pWindow;
	// HRESULT hr = GetDHtmlDocument(&pDocument);
	// pDocument->get_parentWindow(&pWindow);
	// VARIANT ret;
	// ret.vt = VT_EMPTY;
	// CString fun("jsfunc()");
	// pWindow->execScript(fun.AllocSysString(), L"JavaScript", &ret);
	// pDocument->Release();
	// pWindow->Release();

	// Json::Value root;
	// Json::Reader reader;
	// std::wstring str(L"{\"a\":\"aaaa\"}");
	// reader.parse(std::string(CT2A(str.c_str())), root, false);
	// Json::Value a = root["a"];
	// AfxMessageBox(CString(a.asCString()));
	// Json::Value v = root.get("b", "ddd");
	// AfxMessageBox(CString(v.asCString()));
	// std::wstring ttt(CString(var_msg.bstrVal));
	// AfxMessageBox(ttt.c_str());
}

// CmmDlg dialog

BEGIN_DHTML_EVENT_MAP(CmmDlg)
END_DHTML_EVENT_MAP()


CmmDlg::CmmDlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CmmDlg::IDD, CmmDlg::IDH, pParent), m_moving(false), m_playing(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmmDlg, CDHtmlDialog)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CmmDlg message handlers

BOOL CmmDlg::CanAccessExternal()
{
	return TRUE;
}

BOOL CmmDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	EnableAutomation();
	SetExternalDispatch(GetIDispatch(TRUE));

	// TODO: Add extra initialization here
	m_playerDlg.Create(IDD_DLG_PLAYER, this);
	// m_playerDlg.SetWindowPos(0, 20, 70, 0, 0, SWP_NOSIZE|SWP_SHOWWINDOW);
	m_playerDlg.ModifyStyle(DS_MODALFRAME | WS_POPUP | WS_CAPTION | WS_SYSMENU,WS_CHILD);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

BEGIN_DISPATCH_MAP(CmmDlg, CDHtmlDialog)
	DISP_FUNCTION(CmmDlg, "callcpp", callcpp, VT_EMPTY, VTS_VARIANT VTS_VARIANT)
END_DISPATCH_MAP()

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CmmDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDHtmlDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CmmDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CmmDlg::PreTranslateMessage(MSG* pMsg)
{
switch (pMsg->message)
	{
	case WM_LBUTTONDOWN:
		start_moving();
		break;
	case WM_MOUSEMOVE:
		moving();
		break;
	case WM_LBUTTONUP:
		stop_moving();
		break;
	}
	return CDHtmlDialog::PreTranslateMessage(pMsg);
}
