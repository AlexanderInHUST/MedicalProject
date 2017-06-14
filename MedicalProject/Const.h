#include "stdafx.h"

#define AS(a1, a2) answersList->at(a1)->at(a2)
#define AW(b1, b2) answersWeight->at(b1)->at(b2)
#define ASW(a1, a2, b1, b2)  AS(a1, a2) * AW(b1, b2)

#define DEFB(a, b) CButton * map##a##c##b
#define GETB(a, b) map##a##c##b## = (CButton *)GetDlgItem(IDC_MA_P##a##_C##b##)
#define GETB2(a, b) map##a##c##b## = (CButton *)GetDlgItem(IDC_MA7_P##a##_C##b##)

#define SETBE(a, b, result) map##a##c##b##->EnableWindow(result)
#define GETBE(a, b) map##a##c##b##->IsWindowEnabled()

#define SETBC(a, b, result) map##a##c##b##->SetCheck(result)
#define GETBC(a, b) map##a##c##b##->GetCheck()
#define SETBCF(a, b) SETBC(a, b, (answersList->at(a - 1)->at(b - 1) == 1) ? true : false)

#define SETAS(a, b) aList->push_back((GETBC(a, b)))

#define SOLUTION_CHI_1 L"解肌发表、舒经活络"
#define SOLUTION_CHI_2 L"祛风散寒、通经止痛"
#define SOLUTION_CHI_3 L"燥湿化痰、通经止痛"
#define SOLUTION_CHI_4 L"疏肝理气解郁"
#define SOLUTION_CHI_5 L"补气养血通经"
#define SOLUTION_CHI_6 L"养肝益肾"
#define SOLUTION_CHI_7 L"补肾壮阳"

#define EPS 0.00001
#define FILE_NAME "temp.data"