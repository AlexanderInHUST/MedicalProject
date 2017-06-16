// EnglishResultDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MedicalProject.h"
#include "EnglishResultDlg.h"
#include "afxdialogex.h"


// EnglishResultDlg �Ի���

IMPLEMENT_DYNAMIC(EnglishResultDlg, CDialogEx)

EnglishResultDlg::EnglishResultDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(EnglishResultDlg::IDD, pParent)
{

}

EnglishResultDlg::~EnglishResultDlg()
{
}

void EnglishResultDlg::setData(ResultProvider * provider) {
	this->provider = provider;
}

BOOL EnglishResultDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();
	ModifyStyleEx(0, WS_EX_APPWINDOW);
	ShowWindow(SW_SHOW);

	left = (CStatic *)GetDlgItem(IDC_ENG_STA_LEFT);
	right = (CStatic *)GetDlgItem(IDC_ENG_STA_RIGH);
	conclusion = (CStatic *)GetDlgItem(IDC_ENG_STA_CON);
	backBut = (CButton *)GetDlgItem(IDC_ENG_BAK_BUT);
	endBut = (CButton *)GetDlgItem(IDC_ENG_EXIT_BUT);
	leftList = (CListCtrl *)GetDlgItem(IDC_ENG_LEFT_LIST);
	rightList = (CListCtrl *)GetDlgItem(IDC_ENG_RIGH_LIST);

	leftList->SetExtendedStyle(LVS_EX_FULLROWSELECT);

	kaiTiFont1.CreatePointFont(150, L"����");
	kaiTiFont2.CreatePointFont(100, L"����");

	left->SetFont(&kaiTiFont1);
	right->SetFont(&kaiTiFont1);

	backBut->SetFont(&kaiTiFont2);
	endBut->SetFont(&kaiTiFont2);

	deployAll();
	return TRUE;
}

void EnglishResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void EnglishResultDlg::deployAll() {
	deployLeftList();
	deployRightList();
	deployConclusion();
}

void EnglishResultDlg::deployLeftList() {
	LVCOLUMN vc1;
	vc1.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	vc1.pszText = L"����";
	vc1.cx = 120;
	vc1.iSubItem = 0;
	leftList->InsertColumn(0, &vc1);

	vc1.pszText = L"ռ��";
	vc1.cx = 60;
	vc1.iSubItem = 1;
	leftList->InsertColumn(1, &vc1);

	vc1.pszText = L" ";
	vc1.cx = 55;
	vc1.iSubItem = 2;
	leftList->InsertColumn(2, &vc1);

	LVITEM vitem;
	vitem.mask = LVIF_TEXT;
	int count = 0;

	for (auto rep : *(provider->getResult()->getSortedResultEng())) {
		if (rep->pecent1 >= EPS) {
			TCHAR sz[10];
			_stprintf(sz, _T("%.2f"), rep->pecent1);
			leftList->InsertItem(count, const_cast<LPWSTR> (rep->kind->c_str()));
			leftList->SetItemText(count, 1, const_cast<LPWSTR> (sz));
			leftList->SetItemText(count, 2, L"����");
			count++;
		}
	}
}

void EnglishResultDlg::deployRightList() {
	LVCOLUMN vc1;
	vc1.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	vc1.pszText = L"����";
	vc1.cx = 120;
	vc1.iSubItem = 0;
	rightList->InsertColumn(0, &vc1);

	vc1.pszText = L" ";
	vc1.cx = 55;
	vc1.iSubItem = 1;
	rightList->InsertColumn(1, &vc1);

	LVITEM vitem;
	vitem.mask = LVIF_TEXT;
	int count = 0;

	for (auto rep : *getRootReason()) {
		rightList->InsertItem(count, const_cast<LPWSTR> (rep->kind->c_str()));
		rightList->SetItemText(count, 1, L"����");
		count++;
	}
}

vector<ResultPair *> * EnglishResultDlg::getRootReason() {
	vector<ResultPair *> * root = new vector<ResultPair *>;
	for (auto rep : *(provider->getResult()->getSortedResultEng())) {
		if (rep->pecent1 < EPS) {
			root->push_back(rep);
		}
	}
	return root;
}

void EnglishResultDlg::deployConclusion() {
	wstring con1, con2, con3, con4;
	con1 = L"�����β���";
	con2 = L"��δ�������˲��������ǿ�/��׵ר�ơ�\n\n������������ο��������������壩";
	wstring result;
	result = con1;
	if (getRootReason()->size() < 2) {
		con3 = L"���鸴��";
		con4 = L"������ȥҽԺ����Ӧ���";
	}
	else {
		con3 = L"������Լ�";
		con4 = L"�������Ĺ۲�";
	}
	if (provider->getResult()->getSortedResultEng()->at(0)->pecent1 >= 0.4) {
		result = result + con3 + L"����״����" + con4 + L"����ʱ����";
	}
	else {
		result = result + con3 + L"����״������" + con4 + L"��ע������";
	}
	result += con2;
	conclusion->SetWindowTextW(const_cast<LPWSTR> (result.c_str()));
}


BEGIN_MESSAGE_MAP(EnglishResultDlg, CDialogEx)
	
	ON_BN_CLICKED(IDC_ENG_BAK_BUT, &EnglishResultDlg::OnBnClickedEngBakBut)
	ON_BN_CLICKED(IDC_ENG_EXIT_BUT, &EnglishResultDlg::OnBnClickedEngExitBut)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// EnglishResultDlg ��Ϣ�������


void EnglishResultDlg::OnBnClickedEngBakBut()
{
	MedicalProjectChoDlg dlg;
	dlg.setData(provider);
	this->OnOK();
	dlg.DoModal();
}


void EnglishResultDlg::OnBnClickedEngExitBut()
{
	this->OnOK();
}


BOOL EnglishResultDlg::OnEraseBkgnd(CDC* pDC)
{
	CBrush back(RGB(255, 255, 228));
	CBrush * pold = pDC->SelectObject(&back);
	CRect rect;
	pDC->GetClipBox(&rect);
	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(&pold);
	return TRUE;
}


HBRUSH EnglishResultDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	pDC->SetBkMode(TRANSPARENT);
	pDC->SetBkColor(RGB(0, 0, 0));
	return CreateSolidBrush(RGB(255, 255, 228));
}
