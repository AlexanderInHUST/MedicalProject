// MedicalProjectChoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MedicalProject.h"
#include "MedicalProjectChoDlg.h"
#include "afxdialogex.h"


// MedicalProjectChoDlg 对话框

IMPLEMENT_DYNAMIC(MedicalProjectChoDlg, CDialogEx)

MedicalProjectChoDlg::MedicalProjectChoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MedicalProjectChoDlg::IDD, pParent)
{

}

MedicalProjectChoDlg::~MedicalProjectChoDlg()
{
}

void MedicalProjectChoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL MedicalProjectChoDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();
	return TRUE;
}

void MedicalProjectChoDlg::setData(vector<vector<int> *> * answersList) {
	this->answersList = answersList;
	helper = new FileHelper;
	provider = new ResultProvider;
	calculateResult();
}

BEGIN_MESSAGE_MAP(MedicalProjectChoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CH_DLG_BUC, &MedicalProjectChoDlg::OnBnClickedChDlgBuc)
	ON_BN_CLICKED(IDC_CH_DLG_BUE, &MedicalProjectChoDlg::OnBnClickedChDlgBue)
END_MESSAGE_MAP()


// MedicalProjectChoDlg 消息处理程序

void MedicalProjectChoDlg::calculateResult() {
	provider->calResult(answersList, helper->getWeight(FILE_NAME));
}

void MedicalProjectChoDlg::OnBnClickedChDlgBuc()
{
	ChineseResultDlg dlg;
	dlg.setData(provider);
	this->OnOK();
	dlg.DoModal();
}


void MedicalProjectChoDlg::OnBnClickedChDlgBue()
{
	// TODO:  在此添加控件通知处理程序代码
}
