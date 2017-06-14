#pragma once

#include "stdafx.h"
#include "ResultProvider.h"
#include "FileHelper.h"
#include "ChineseResultDlg.h"
#include "EnglishResultDlg.h"

// MedicalProjectChoDlg 对话框

class MedicalProjectChoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MedicalProjectChoDlg)

public:
	MedicalProjectChoDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MedicalProjectChoDlg();
	
	void setData(vector<vector<int> *> * answersList);
	void setData(ResultProvider * provider);

// 对话框数据
	enum { IDD = IDD_CHOS_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	
	void calculateResult();

	vector<vector<int> *> * answersList;
	ResultProvider * provider;
	FileHelper * helper;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedChDlgBuc();
	afx_msg void OnBnClickedChDlgBue();
};
