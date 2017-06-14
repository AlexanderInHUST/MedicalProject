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
	ModifyStyleEx(0, WS_EX_APPWINDOW);
	ShowWindow(SW_SHOW);
	return TRUE;
}

void MedicalProjectChoDlg::setData(vector<vector<int> *> * answersList) {
	this->answersList = answersList;
	helper = new FileHelper;
	provider = new ResultProvider;
	calculateResult();
}

void MedicalProjectChoDlg::setData(ResultProvider * provider) {
	this->provider = provider;
}


BEGIN_MESSAGE_MAP(MedicalProjectChoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CH_DLG_BUC, &MedicalProjectChoDlg::OnBnClickedChDlgBuc)
	ON_BN_CLICKED(IDC_CH_DLG_BUE, &MedicalProjectChoDlg::OnBnClickedChDlgBue)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
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
	EnglishResultDlg dlg;
	dlg.setData(provider);
	this->OnOK();
	dlg.DoModal();
}


BOOL MedicalProjectChoDlg::OnEraseBkgnd(CDC* pDC)
{
	CBrush back(RGB(255, 255, 228));
	CBrush * pold = pDC->SelectObject(&back);
	CRect rect;
	pDC->GetClipBox(&rect);
	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(&pold);
	return TRUE;
}


HBRUSH MedicalProjectChoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	pDC->SetBkMode(TRANSPARENT);
	pDC->SetBkColor(RGB(0, 0, 0));
	return CreateSolidBrush(RGB(255, 255, 228));
}
