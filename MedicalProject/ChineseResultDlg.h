#pragma once


// ChineseResultDlg �Ի���

class ChineseResultDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChineseResultDlg)

public:
	ChineseResultDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ChineseResultDlg();

// �Ի�������
	enum { IDD = IDD_CHI_RES_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
