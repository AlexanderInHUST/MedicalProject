#pragma once


// EnglishResultDlg �Ի���

class EnglishResultDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EnglishResultDlg)

public:
	EnglishResultDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~EnglishResultDlg();

// �Ի�������
	enum { IDD = IDD_ENG_RES_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEngLefText();
};
