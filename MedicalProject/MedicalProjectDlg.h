
// MedicalProjectDlg.h : ͷ�ļ�
//

#pragma once


// CMedicalProjectDlg �Ի���
class CMedicalProjectDlg : public CDialogEx
{
// ����
public:
	CMedicalProjectDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MEDICALPROJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
