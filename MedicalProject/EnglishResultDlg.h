#pragma once

#include "ResultProvider.h"
#include "MedicalProjectChoDlg.h"
// EnglishResultDlg 对话框

class MedicalProjectChoDlg;

class EnglishResultDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EnglishResultDlg)

public:
	EnglishResultDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~EnglishResultDlg();

// 对话框数据
	enum { IDD = IDD_ENG_RES_DLG };

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

	ResultProvider * provider;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEngLefText();
	void setData(ResultProvider * provider);
	afx_msg void OnBnClickedEngBakBut();
	afx_msg void OnBnClickedEngExitBut();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
