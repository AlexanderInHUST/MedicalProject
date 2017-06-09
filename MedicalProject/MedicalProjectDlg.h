
// MedicalProjectDlg.h : 头文件
//

#pragma once


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

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeMaPro1Text();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedMaP2C3();
	afx_msg void OnBnClickedMaP4C5();
};
