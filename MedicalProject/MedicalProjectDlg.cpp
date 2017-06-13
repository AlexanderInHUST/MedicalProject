// MedicalProjectDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicalProject.h"
#include "MedicalProjectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMedicalProjectDlg �Ի���



CMedicalProjectDlg::CMedicalProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMedicalProjectDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMedicalProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMedicalProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MA_P1_C1, &CMedicalProjectDlg::OnBnClickedMaP1C1)
	ON_BN_CLICKED(IDC_MA_P1_C2, &CMedicalProjectDlg::OnBnClickedMaP1C2)
	ON_BN_CLICKED(IDC_MA_P1_C3, &CMedicalProjectDlg::OnBnClickedMaP1C3)
	ON_BN_CLICKED(IDC_MA_P1_C4, &CMedicalProjectDlg::OnBnClickedMaP1C4)
	ON_BN_CLICKED(IDC_MA_P2_C1, &CMedicalProjectDlg::OnBnClickedMaP2C1)
	ON_BN_CLICKED(IDC_MA_P2_C2, &CMedicalProjectDlg::OnBnClickedMaP2C2)
	ON_BN_CLICKED(IDC_MA_P2_C3, &CMedicalProjectDlg::OnBnClickedMaP2C3)
	ON_BN_CLICKED(IDC_MA_NEX_BUT, &CMedicalProjectDlg::OnBnClickedMaNexBut)
END_MESSAGE_MAP()


// CMedicalProjectDlg ��Ϣ�������

BOOL CMedicalProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	//map61c1 = (CButton *)GetDlgItem(IDC_MA_P61_C1);
	GETB(1, 1); GETB(1, 2); GETB(1, 3); GETB(1, 4);
	GETB(2, 1); GETB(2, 2); GETB(2, 3); GETB(2, 4);
	GETB(3, 1); GETB(3, 2); GETB(3, 3);
	GETB(4, 1); GETB(4, 2); GETB(4, 3); GETB(4, 4); GETB(4, 5); GETB(4, 6); GETB(4, 7); GETB(4, 8);
	GETB(5, 1); GETB(5, 2); GETB(5, 3);
	GETB(61, 1); GETB(61, 2); GETB(61, 3); GETB(61, 4);
	GETB(62, 1); GETB(62, 2); GETB(62, 3); GETB(62, 4); GETB(62, 5);
	GETB(63, 1); GETB(63, 2); GETB(63, 3); GETB(63, 4);

	SETBE(61, 1, false); SETBE(61, 2, false); SETBE(61, 3, false); SETBE(61, 4, false);
	SETBE(62, 1, false); SETBE(62, 2, false); SETBE(62, 3, false); SETBE(62, 4, false); SETBE(62, 5, false);
	SETBE(63, 1, false); SETBE(63, 2, false); SETBE(63, 3, false); SETBE(63, 4, false);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMedicalProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMedicalProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMedicalProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMedicalProjectDlg::OnBnClickedMaP1C1() {
	SETBE(2, 1, false); SETBE(2, 2, true); SETBE(2, 3, true); SETBE(2, 4, true);
	SETBE(61, 1, true); SETBE(61, 2, true); SETBE(61, 3, true); SETBE(61, 4, true);
	if (GETBC(2, 2) == 0) {
		SETBE(62, 1, false); SETBE(62, 2, false); SETBE(62, 3, false); SETBE(62, 4, false); SETBE(62, 5, false);
	}
	if (GETBC(2, 3) == 0) {
		SETBE(63, 1, false); SETBE(63, 2, false); SETBE(63, 3, false); SETBE(63, 4, false);
	}
}

void CMedicalProjectDlg::OnBnClickedMaP1C2() {
	SETBE(2, 1, true); SETBE(2, 2, false); SETBE(2, 3, true); SETBE(2, 4, true);
	if (GETBC(2, 1) == 0) {
		SETBE(61, 1, false); SETBE(61, 2, false); SETBE(61, 3, false); SETBE(61, 4, false);
	}
	SETBE(62, 1, true); SETBE(62, 2, true); SETBE(62, 3, true); SETBE(62, 4, true); SETBE(62, 5, true);
	if (GETBC(2, 3) == 0) {
		SETBE(63, 1, false); SETBE(63, 2, false); SETBE(63, 3, false); SETBE(63, 4, false);
	}
}

void CMedicalProjectDlg::OnBnClickedMaP1C3() {
	SETBE(2, 1, true); SETBE(2, 2, true); SETBE(2, 3, false); SETBE(2, 4, true);
	if (GETBC(2, 1) == 0) {
		SETBE(61, 1, false); SETBE(61, 2, false); SETBE(61, 3, false); SETBE(61, 4, false);
	}
	if (GETBC(2, 2) == 0) {
		SETBE(62, 1, false); SETBE(62, 2, false); SETBE(62, 3, false); SETBE(62, 4, false); SETBE(62, 5, false);
	}
	SETBE(63, 1, true); SETBE(63, 2, true); SETBE(63, 3, true); SETBE(63, 4, true);
}


void CMedicalProjectDlg::OnBnClickedMaP1C4() {
	SETBE(2, 1, true); SETBE(2, 2, true); SETBE(2, 3, true); SETBE(2, 4, false);
	SETBE(61, 1, false); SETBE(61, 2, false); SETBE(61, 3, false); SETBE(61, 4, false);
	SETBE(62, 1, false); SETBE(62, 2, false); SETBE(62, 3, false); SETBE(62, 4, false); SETBE(62, 5, false);
	SETBE(63, 1, false); SETBE(63, 2, false); SETBE(63, 3, false); SETBE(63, 4, false);
}


void CMedicalProjectDlg::OnBnClickedMaP2C1() {
	if (GETBC(2, 1) == 1) {
		SETBE(61, 1, true); SETBE(61, 2, true); SETBE(61, 3, true); SETBE(61, 4, true);
	} else if (GETBC(2, 1) == 0) {
		SETBE(61, 1, false); SETBE(61, 2, false); SETBE(61, 3, false); SETBE(61, 4, false);
	}
}


void CMedicalProjectDlg::OnBnClickedMaP2C2() {
	if (GETBC(2, 2) == 1) {
		SETBE(62, 1, true); SETBE(62, 2, true); SETBE(62, 3, true); SETBE(62, 4, true); SETBE(62, 5, true);
	}
	else if (GETBC(2, 2) == 0) {
		SETBE(62, 1, false); SETBE(62, 2, false); SETBE(62, 3, false); SETBE(62, 4, false); SETBE(62, 5, false);
	}
}


void CMedicalProjectDlg::OnBnClickedMaP2C3() {
	if (GETBC(2, 3) == 1) {
		SETBE(63, 1, true); SETBE(63, 2, true); SETBE(63, 3, true); SETBE(63, 4, true);
	}
	else if (GETBC(2, 3) == 0) {
		SETBE(63, 1, false); SETBE(63, 2, false); SETBE(63, 3, false); SETBE(63, 4, false);
	}
}

void CMedicalProjectDlg::OnBnClickedMaNexBut() {
	vector<vector<int> *> * answersList = new vector<vector<int>*>;
	MedicalProjectDlg2 dlg2;

	vector<int> * aList = new vector<int>;
	SETAS(1, 1); SETAS(1, 2); SETAS(1, 3); SETAS(1, 4);
	answersList->push_back(aList);

	aList = new vector<int>;
	SETAS(2, 1); SETAS(2, 2); SETAS(2, 3); SETAS(2, 4);
	answersList->push_back(aList);

	aList = new vector<int>;
	SETAS(3, 1); SETAS(3, 2); SETAS(3, 3);
	answersList->push_back(aList);

	aList = new vector<int>;
	SETAS(4, 1); SETAS(4, 2); SETAS(4, 3); SETAS(4, 4); SETAS(4, 5); SETAS(4, 6); SETAS(4, 7); SETAS(4, 8);
	answersList->push_back(aList);

	aList = new vector<int>;
	SETAS(5, 1); SETAS(5, 2); SETAS(5, 3);
	answersList->push_back(aList);

	vector<int> * a61List = new vector<int>;
	a61List->push_back((GETBE(61, 1)) ? GETBC(61, 1) : 0);
	a61List->push_back((GETBE(61, 2)) ? GETBC(61, 2) : 0);
	a61List->push_back((GETBE(61, 3)) ? GETBC(61, 3) : 0);
	a61List->push_back((GETBE(61, 4)) ? GETBC(61, 4) : 0);

	vector<int> * a62List = new vector<int>;
	a62List->push_back((GETBE(62, 1)) ? GETBC(62, 1) : 0);
	a62List->push_back((GETBE(62, 2)) ? GETBC(62, 2) : 0);
	a62List->push_back((GETBE(62, 3)) ? GETBC(62, 3) : 0);
	a62List->push_back((GETBE(62, 4)) ? GETBC(62, 4) : 0);
	a62List->push_back((GETBE(62, 5)) ? GETBC(62, 5) : 0);

	vector<int> * a63List = new vector<int>;
	a63List->push_back((GETBE(63, 1)) ? GETBC(63, 1) : 0);
	a63List->push_back((GETBE(63, 2)) ? GETBC(63, 2) : 0);
	a63List->push_back((GETBE(63, 3)) ? GETBC(63, 3) : 0);
	a63List->push_back((GETBE(63, 4)) ? GETBC(63, 4) : 0);

	this->OnOK();
	dlg2.setData(answersList, a61List, a62List, a63List);
	dlg2.DoModal();
}
