#pragma once

			    
// CPlayerDlg �Ի���

class CPlayerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayerDlg)

public:
	CPlayerDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPlayerDlg();

// �Ի�������
	enum { IDD = IDD_DLG_PLAYER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
