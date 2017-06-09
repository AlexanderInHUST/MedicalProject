#pragma once


// EnglishResultDlg 对话框

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

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEngLefText();
};
