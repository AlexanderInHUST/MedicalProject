#pragma once

#include "Answers.h"
// MedicalProjectDlg2 对话框

class MedicalProjectDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(MedicalProjectDlg2)

public:
	MedicalProjectDlg2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MedicalProjectDlg2();
	void setData(vector<vector<int> *> * answersList, vector<int> * a61List, vector<int> * a62List, vector<int> * a63List);

// 对话框数据
	enum { IDD = IDD_MEDICALPROJECT2_DIALOG };

protected:
	Answers answer;
	vector<vector<int> *> * answersList;
	vector<int> * a61List;
	vector<int> * a62List;
	vector<int> * a63List;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
