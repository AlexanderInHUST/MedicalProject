// EnglishResultDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicalProject.h"
#include "EnglishResultDlg.h"
#include "afxdialogex.h"


// EnglishResultDlg �Ի���

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


// EnglishResultDlg ��Ϣ�������


void EnglishResultDlg::OnEnChangeEngLefText()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
