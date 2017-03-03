
// mmDlg.h : header file
//

#include "./PlayerDlg.h"

#pragma once


// CmmDlg dialog
class CmmDlg : public CDHtmlDialog
{
private:
	void switch2play();
	void start_moving();
	void stop_moving();
	void moving();
private:
	bool m_playing;
private:
	bool m_moving;
	CRect m_rc;
	CPoint m_pt;
	CPlayerDlg m_playerDlg;
	void callcpp(const VARIANT& type, const VARIANT& msg);
// Construction
public:
	CmmDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MM_DIALOG, IDH = IDR_HTML_MM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	BOOL PreTranslateMessage(MSG* pMsg);
	// Implementation
protected:
	HICON m_hIcon;
	virtual BOOL CanAccessExternal();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
	DECLARE_DISPATCH_MAP()
};
