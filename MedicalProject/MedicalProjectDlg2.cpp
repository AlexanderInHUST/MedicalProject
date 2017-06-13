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

BOOL MedicalProjectDlg2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	GETB2(7, 1); GETB2(7, 2); GETB2(7, 3); GETB2(7, 4); GETB2(7, 5);
	GETB2(8, 1); GETB2(8, 2); GETB2(8, 3); GETB2(8, 4); GETB2(8, 5);
	GETB2(9, 1); GETB2(9, 2); GETB2(9, 3); GETB2(9, 4); GETB2(9, 5); GETB2(9, 6);
	GETB2(10, 1); GETB2(10, 2); GETB2(10, 3);
	GETB2(11, 1); GETB2(11, 2); GETB2(11, 3); GETB2(11, 4); GETB2(11, 5); GETB2(11, 6);
	GETB2(12, 1); GETB2(12, 2); GETB2(12, 3); GETB2(12, 4);
	GETB2(13, 1); GETB2(13, 2); GETB2(13, 3); GETB2(13, 4);
	GETB2(14, 1); GETB2(14, 2); GETB2(14, 3);
	GETB2(15, 1); GETB2(15, 2); GETB2(15, 3); GETB2(15, 4);
	return TRUE;
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
	vector<int> * aList = new vector<int>;
	SETAS(7, 1); SETAS(7, 2); SETAS(7, 3); SETAS(7, 4); SETAS(7, 5);
	answersList->push_back(aList);

	aList = new vector<int>;
	SETAS(8, 1); SETAS(8, 2); SETAS(8, 3); SETAS(8, 4); SETAS(8, 5);
	answersList->push_back(aList);

	aList = new vector<int>;
	SETAS(9, 1); SETAS(9, 2); SETAS(9, 3); SETAS(9, 4); SETAS(9, 5); SETAS(9, 6);
	answersList->push_back(aList);

	aList = new vector<int>;
	SETAS(10, 1); SETAS(10, 2); SETAS(10, 3);
	answersList->push_back(aList);

	aList = new vector<int>;
	SETAS(11, 1); SETAS(11, 2); SETAS(11, 3); SETAS(11, 4); SETAS(11, 5); SETAS(11, 6);
	answersList->push_back(aList);

	aList = new vector<int>;
	SETAS(12, 1); SETAS(12, 2); SETAS(12, 3); SETAS(12, 4);
	answersList->push_back(aList);

	aList = new vector<int>;
	SETAS(13, 1); SETAS(13, 2); SETAS(13, 3); SETAS(13, 4);
	answersList->push_back(aList);

	aList = new vector<int>;
	SETAS(14, 1); SETAS(14, 2); SETAS(14, 3);
	answersList->push_back(aList);

	aList = new vector<int>;
	SETAS(15, 1); SETAS(15, 2); SETAS(15, 3); SETAS(15, 4);
	answersList->push_back(aList);
	answersList->push_back(a61List);
	answersList->push_back(a62List);
	answersList->push_back(a63List);
}


void MedicalProjectDlg2::OnBnClickedMa2PreBut()
{
	CMedicalProjectDlg dlg;
	this->OnOK();
	dlg.setData(answersList, a61List, a62List, a63List);
	dlg.DoModal();
}