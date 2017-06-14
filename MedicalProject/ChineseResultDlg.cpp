// ChineseResultDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MedicalProject.h"
#include "ChineseResultDlg.h"
#include "afxdialogex.h"


// ChineseResultDlg 对话框

IMPLEMENT_DYNAMIC(ChineseResultDlg, CDialogEx)

ChineseResultDlg::ChineseResultDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ChineseResultDlg::IDD, pParent)
{

}

ChineseResultDlg::~ChineseResultDlg()
{
}

void ChineseResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL ChineseResultDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	return TRUE;
}

BEGIN_MESSAGE_MAP(ChineseResultDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CHI_BAK_BUT, &ChineseResultDlg::OnBnClickedChiBakBut)
END_MESSAGE_MAP()


// ChineseResultDlg 消息处理程序


void ChineseResultDlg::OnBnClickedChiBakBut()
{
	// TODO:  在此添加控件通知处理程序代码
}
