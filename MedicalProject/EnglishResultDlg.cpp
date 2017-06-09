// EnglishResultDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MedicalProject.h"
#include "EnglishResultDlg.h"
#include "afxdialogex.h"


// EnglishResultDlg 对话框

IMPLEMENT_DYNAMIC(EnglishResultDlg, CDialogEx)

EnglishResultDlg::EnglishResultDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(EnglishResultDlg::IDD, pParent)
{

}

EnglishResultDlg::~EnglishResultDlg()
{
}

void EnglishResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(EnglishResultDlg, CDialogEx)
	ON_EN_CHANGE(IDC_ENG_LEF_TEXT, &EnglishResultDlg::OnEnChangeEngLefText)
END_MESSAGE_MAP()


// EnglishResultDlg 消息处理程序


void EnglishResultDlg::OnEnChangeEngLefText()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
