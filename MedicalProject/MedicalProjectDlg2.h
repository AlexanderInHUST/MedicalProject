#pragma once

#include "Answers.h"
// MedicalProjectDlg2 �Ի���

class MedicalProjectDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(MedicalProjectDlg2)

public:
	MedicalProjectDlg2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MedicalProjectDlg2();
	void setData(vector<vector<int> *> * answersList, vector<int> * a61List, vector<int> * a62List, vector<int> * a63List);

// �Ի�������
	enum { IDD = IDD_MEDICALPROJECT2_DIALOG };

protected:
	Answers answer;
	vector<vector<int> *> * answersList;
	vector<int> * a61List;
	vector<int> * a62List;
	vector<int> * a63List;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
