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
END_MESSAGE_MAP()


// MedicalProjectDlg2 消息处理程序