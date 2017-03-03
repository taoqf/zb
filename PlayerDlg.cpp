// PlayerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "mm.h"
#include "PlayerDlg.h"
#include "afxdialogex.h"


// CPlayerDlg 对话框

IMPLEMENT_DYNAMIC(CPlayerDlg, CDialogEx)

CPlayerDlg::CPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPlayerDlg::IDD, pParent)
{

}

CPlayerDlg::~CPlayerDlg()
{
}

void CPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPlayerDlg, CDialogEx)
END_MESSAGE_MAP()


// CPlayerDlg 消息处理程序
