#pragma once

#include "Result.h"

// ChineseResultDlg 对话框

class ChineseResultDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChineseResultDlg)

public:
	ChineseResultDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ChineseResultDlg();

// 对话框数据
	enum { IDD = IDD_CHI_RES_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	Result * result;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedChiBakBut();
	afx_msg void OnEnChangeChiLefText();
};
