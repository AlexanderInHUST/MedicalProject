#pragma once

#include "ResultProvider.h"
#include "MedicalProjectChoDlg.h"

// ChineseResultDlg 对话框

class MedicalProjectChoDlg;

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
	void deployAll();
	void deployLeftList();
	void deployRightList();
	void deployConclusion();
	vector<ResultPair *> * getRootReason();
	wstring getSolution(wstring * kind);

	CStatic * left;
	CStatic * right;
	CStatic * conclusion;

	CFont kaiTiFont1;
	CFont kaiTiFont2;

	CButton * backBut;
	CButton * endBut;

	CListCtrl * leftList;
	CListCtrl * rightList;

	CBrush * backBrush;

	ResultProvider * provider;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedChiBakBut();
	afx_msg void OnEnChangeChiLefText();
	void setData(ResultProvider * provider);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedChiExitBut();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
