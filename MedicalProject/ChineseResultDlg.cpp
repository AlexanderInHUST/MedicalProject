// ChineseResultDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicalProject.h"
#include "ChineseResultDlg.h"
#include "afxdialogex.h"


// ChineseResultDlg �Ի���

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


// ChineseResultDlg ��Ϣ�������


void ChineseResultDlg::OnBnClickedChiBakBut()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
