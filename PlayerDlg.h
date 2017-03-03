#pragma once

			    
// CPlayerDlg 对话框

class CPlayerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayerDlg)

public:
	CPlayerDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPlayerDlg();

// 对话框数据
	enum { IDD = IDD_DLG_PLAYER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
