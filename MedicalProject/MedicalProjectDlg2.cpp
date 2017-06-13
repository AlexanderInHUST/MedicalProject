// MedicalProjectDlg2.cpp : 实现文件
//

#include "stdafx.h"
#include "MedicalProject.h"
#include "MedicalProjectDlg2.h"
#include "afxdialogex.h"


// MedicalProjectDlg2 对话框

IMPLEMENT_DYNAMIC(MedicalProjectDlg2, CDialogEx)

MedicalProjectDlg2::MedicalProjectDlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(MedicalProjectDlg2::IDD, pParent)
{
	this->answersList = NULL;
	this->a61List = NULL;
	this->a62List = NULL;
	this->a63List = NULL;
}

MedicalProjectDlg2::~MedicalProjectDlg2() {

}

void MedicalProjectDlg2::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
}

void MedicalProjectDlg2::setData(vector<vector<int> *> * answersList, vector<int> * a61List, vector<int> * a62List, vector<int> * a63List) {
	this->answersList = answersList;
	this->a61List = a61List;
	this->a62List = a62List;
	this->a63List = a63List;
}


BEGIN_MESSAGE_MAP(MedicalProjectDlg2, CDialogEx)
	ON_BN_CLICKED(IDC_MA2_NEX_BUT, &MedicalProjectDlg2::OnBnClickedMa2NexBut)
	ON_BN_CLICKED(IDC_MA2_PRE_BUT, &MedicalProjectDlg2::OnBnClickedMa2PreBut)
END_MESSAGE_MAP()


// MedicalProjectDlg2 消息处理程序

void MedicalProjectDlg2::OnBnClickedMa2NexBut()
{
	// TODO:  在此添加控件通知处理程序代码
}


void MedicalProjectDlg2::OnBnClickedMa2PreBut()
{
	CMedicalProjectDlg dlg;
	this->OnOK();
	dlg.setData(answersList, a61List, a62List, a63List);
	dlg.DoModal();
}
