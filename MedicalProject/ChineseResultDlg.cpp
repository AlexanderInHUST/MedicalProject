// ChineseResultDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MedicalProject.h"
#include "ChineseResultDlg.h"
#include "afxdialogex.h"


// ChineseResultDlg 对话框

IMPLEMENT_DYNAMIC(ChineseResultDlg, CDialogEx)

ChineseResultDlg::ChineseResultDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ChineseResultDlg::IDD, pParent)
{

}

ChineseResultDlg::~ChineseResultDlg()
{
}

void ChineseResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL ChineseResultDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();
	ModifyStyleEx(0, WS_EX_APPWINDOW);
	ShowWindow(SW_SHOW);

	left = (CStatic *)GetDlgItem(IDC_CHI_STA_LEFT);
	right = (CStatic *)GetDlgItem(IDC_CHI_STA_RIGH);
	conclusion = (CStatic *)GetDlgItem(IDC_CHI_STA_CON);
	backBut = (CButton *)GetDlgItem(IDC_CHI_BAK_BUT);
	endBut = (CButton *)GetDlgItem(IDC_CHI_EXIT_BUT);
	leftList = (CListCtrl *)GetDlgItem(IDC_CHI_LEFT_LIST);
	rightList = (CListCtrl *)GetDlgItem(IDC_CHI_RIGH_LIST);

	leftList->SetExtendedStyle(LVS_EX_FULLROWSELECT);

	kaiTiFont1.CreatePointFont(150, L"楷体");
	kaiTiFont2.CreatePointFont(100, L"楷体");

	left->SetFont(&kaiTiFont1);
	right->SetFont(&kaiTiFont1);

	backBut->SetFont(&kaiTiFont2);
	endBut->SetFont(&kaiTiFont2);

	deployAll();

	return TRUE;
}

BEGIN_MESSAGE_MAP(ChineseResultDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CHI_BAK_BUT, &ChineseResultDlg::OnBnClickedChiBakBut)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CHI_EXIT_BUT, &ChineseResultDlg::OnBnClickedChiExitBut)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// ChineseResultDlg 消息处理程序

void ChineseResultDlg::setData(ResultProvider * provider) {
	this->provider = provider;
}

void ChineseResultDlg::deployAll() {
	deployLeftList();
	deployRightList();
	deployConclusion();
}

void ChineseResultDlg::deployLeftList() {
	LVCOLUMN vc1;
	vc1.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	vc1.pszText = L"病机";
	vc1.cx = 85;
	vc1.iSubItem = 0;
	leftList->InsertColumn(0, &vc1);

	vc1.pszText = L"占比";
	vc1.cx = 55;
	vc1.iSubItem = 1;
	leftList->InsertColumn(1, &vc1);

	vc1.pszText = L" ";
	vc1.cx = 40;
	vc1.iSubItem = 2;
	leftList->InsertColumn(2, &vc1);

	LVITEM vitem;
	vitem.mask = LVIF_TEXT;
	int count = 0;

	for (auto rep : *(provider->getResult()->getSortedResultChi())) {
		if (rep->pecent1 >= EPS) {
			TCHAR sz[10];
			_stprintf(sz, _T("%d%%"),  (int)((rep->pecent1 * 100)));
			leftList->InsertItem(count, const_cast<LPWSTR> (rep->kind->c_str()));
			leftList->SetItemText(count, 1, const_cast<LPWSTR> (sz));
			leftList->SetItemText(count, 2, L"详情");
			count++;
		}
	}
}

void ChineseResultDlg::deployRightList() {
	LVCOLUMN vc1;
	vc1.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
	vc1.pszText = L"病机";
	vc1.cx = 85;
	vc1.iSubItem = 0;
	rightList->InsertColumn(0, &vc1);

	vc1.pszText = L"占比";
	vc1.cx = 55;
	vc1.iSubItem = 1;
	rightList->InsertColumn(1, &vc1);

	vc1.pszText = L" ";
	vc1.cx = 40;
	vc1.iSubItem = 2;
	rightList->InsertColumn(2, &vc1);

	LVITEM vitem;
	vitem.mask = LVIF_TEXT;
	int count = 0;

	vector<ResultPair *> * rootList = getRootReason();
	float tempAmount = 0;

	for (auto rep : *rootList) {
		tempAmount += rep->pecent1;
	}

	for (auto rep : *rootList) {
		if (rep->pecent1 >= EPS) {
			TCHAR sz[10];
			_stprintf(sz, _T("%d%%"), (int)((rep->pecent1 / tempAmount) * 100));
			rightList->InsertItem(count, const_cast<LPWSTR> (rep->kind->c_str()));
			rightList->SetItemText(count, 1, const_cast<LPWSTR> (sz));
			rightList->SetItemText(count, 2, L"详情");
			count++;
		}
	}
}

void ChineseResultDlg::deployConclusion() {
	wstring con1, con2, con3, con4, con5;
	con1 = L"您本次不适多因";
	con2 = L"为主要证型";
	con3 = L"。治法宜";
	con4 = L"为主";
	con5 = L"。\n\n（本结果仅做参考，不具诊疗意义）";
	wstring result;

	FileHelper helper;
	vector<ResultPair *> * rootList = getRootReason();
	float tempAmount = 0;
	float value = helper.getWeight("med.data")->at(8)->at(0);

	for (auto rep : *rootList) {
		tempAmount += rep->pecent1;
	}

	result = con1;
	result += *(provider->getResult()->getSortedResultChi()->at(0)->kind);
	result += con2;
	vector<ResultPair *> * root = getRootReason();
	if (root->at(0)->pecent1 / tempAmount >= value) {
		result += L"，并有";
		result += *(root->at(0)->kind);
		if (root->at(1)->pecent1 / tempAmount >= value) {
			result += L"、";
			result += *(root->at(1)->kind);
		}
		result += L"（等）为根本兼证";
	}
	result += con3;
	result += getSolution((provider->getResult()->getSortedResultChi()->at(0)->kind));
	result += con4;

	if (root->at(0)->pecent1 / tempAmount >= value) {
		result += L"，考虑";
		result += getSolution((root->at(0)->kind));
		if (root->at(1)->pecent1 / tempAmount >= value) {
			result += L"、";
			result += getSolution((root->at(1)->kind));
		}
	}
	result += con5;
	conclusion->SetWindowTextW(const_cast<LPWSTR> (result.c_str()));
}

vector<ResultPair *> * ChineseResultDlg::getRootReason() {
	vector<ResultPair *> * root = new vector<ResultPair *>;
	for (auto rep : *(provider->getResult()->getSortedResultChi())) {
		if (!rep->kind->compare(L"太阳经输不利"))
			continue;
		if (!rep->kind->compare(L"风寒痹阻"))
			continue;
		if (!rep->kind->compare(L"痰湿阻络"))
			continue;
		root->push_back(rep);
	}
	return root;
}

wstring ChineseResultDlg::getSolution(wstring * kind) {
	if (kind->compare(L"太阳经输不利")) {
		return SOLUTION_CHI_1;
	}
	else if (kind->compare(L"风寒痹阻")) {
		return SOLUTION_CHI_2;
	}
	else if (kind->compare(L"痰湿阻络")) {
		return SOLUTION_CHI_3;
	}
	else if (kind->compare(L"肝气郁结")) {
		return SOLUTION_CHI_4;
	}
	else if (kind->compare(L"气血亏虚")) {
		return SOLUTION_CHI_5;
	}
	else if (kind->compare(L"肝肾不足")) {
		return SOLUTION_CHI_6;
	}
	else if (kind->compare(L"肾阳虚")) {
		return SOLUTION_CHI_7;
	}
	return L"无";
}

void ChineseResultDlg::OnBnClickedChiExitBut()
{
	this->OnOK();
}

void ChineseResultDlg::OnBnClickedChiBakBut()
{
	MedicalProjectChoDlg dlg;
	dlg.setData(provider);
	this->OnOK();
	dlg.DoModal();
}

BOOL ChineseResultDlg::OnEraseBkgnd(CDC* pDC)
{
	CBrush back(RGB(255, 255, 228));
	CBrush * pold = pDC->SelectObject(&back);
	CRect rect;
	pDC->GetClipBox(&rect);
	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(&pold);
	return TRUE;
}


HBRUSH ChineseResultDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	pDC->SetBkMode(TRANSPARENT);
	pDC->SetBkColor(RGB(0, 0, 0));
	return CreateSolidBrush(RGB(255, 255, 228));
}