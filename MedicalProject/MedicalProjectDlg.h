
// MedicalProjectDlg.h : 头文件
//

#pragma once

#include "Const.h"
#include "Answers.h"
#include "MedicalProjectDlg2.h"

// CMedicalProjectDlg 对话框
class CMedicalProjectDlg : public CDialogEx
{
// 构造
public:
	CMedicalProjectDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MEDICALPROJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CButton * map1c1, * map1c2, * map1c3, * map1c4;
	CButton * map2c1, * map2c2, * map2c3, * map2c4;
	CButton * map3c1, * map3c2, * map3c3;
	CButton * map4c1, * map4c2, * map4c3, * map4c4, * map4c5, * map4c6, * map4c7, * map4c8;
	CButton * map5c1, * map5c2, * map5c3;
	CButton * map61c1, * map61c2, * map61c3, * map61c4;
	CButton * map62c1, * map62c2, * map62c3, * map62c4, * map62c5;
	CButton * map63c1, * map63c2, * map63c3, * map63c4;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeMaPro1Text();
	afx_msg void OnBnClickedMaP1C1();
	afx_msg void OnBnClickedMaP1C2();
	afx_msg void OnBnClickedMaP1C3();
	afx_msg void OnBnClickedMaP1C4();
	afx_msg void OnBnClickedMaP2C1();
	afx_msg void OnBnClickedMaP2C2();
	afx_msg void OnBnClickedMaP2C3();
	afx_msg void OnBnClickedMaP2C4();
	afx_msg void OnBnClickedMaNexBut();
};
