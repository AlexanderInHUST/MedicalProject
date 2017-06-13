#pragma once

#include "stdafx.h"
#include "Answers.h"
#include "Const.h"
#include "MedicalProjectDlg.h"
// MedicalProjectDlg2 对话框

class CMedicalProjectDlg;
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

	DEFB(7, 1); DEFB(7, 2); DEFB(7, 3); DEFB(7, 4); DEFB(7, 5);
	DEFB(8, 1); DEFB(8, 2); DEFB(8, 3); DEFB(8, 4); DEFB(8, 5);
	DEFB(9, 1); DEFB(9, 2); DEFB(9, 3); DEFB(9, 4); DEFB(9, 5); DEFB(9, 6);
	DEFB(10, 1); DEFB(10, 2); DEFB(10, 3);
	DEFB(11, 1); DEFB(11, 2); DEFB(11, 3); DEFB(11, 4); DEFB(11, 5); DEFB(11, 6);
	DEFB(12, 1); DEFB(12, 2); DEFB(12, 3); DEFB(12, 4);
	DEFB(13, 1); DEFB(13, 2); DEFB(13, 3); DEFB(13, 4);
	DEFB(14, 1); DEFB(14, 2); DEFB(14, 3);
	DEFB(15, 1); DEFB(15, 2); DEFB(15, 3); DEFB(15, 4);

	Answers answer;
	vector<vector<int> *> * answersList;
	vector<int> * a61List;
	vector<int> * a62List;
	vector<int> * a63List;
	CMedicalProjectDlg * preDlg;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck9();
	afx_msg void OnBnClickedCheck14();
	afx_msg void OnBnClickedCheck20();
	afx_msg void OnBnClickedMa2NexBut();
	afx_msg void OnBnClickedMa2PreBut();
	afx_msg void OnBnClickedMa7P7C2();
	afx_msg void OnBnClickedMa7P9C3();
};
