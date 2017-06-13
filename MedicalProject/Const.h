#include "stdafx.h"

#define AS(a1, a2) answersList->at(a1)->at(a2)
#define AW(b1, b2) answersWeight->at(b1)->at(b2)
#define ASW(a1, a2, b1, b2)  AS(a1, a2) * AW(b1, b2)

#define DEFB(a, b) CButton * map##a##c##b
#define GETB(a, b) map##a##c##b## = (CButton *)GetDlgItem(IDC_MA_P##a##_C##b##)

#define SETBE(a, b, result) map##a##c##b##->EnableWindow(result)
#define GETBE(a, b) map##a##c##b##->IsWindowEnabled()

#define SETBC(a, b, result) map##a##c##b##->SetCheck(result)
#define GETBC(a, b) map##a##c##b##->GetCheck()
#define SETBCF(a, b) SETBC(a, b, (answersList->at(a - 1)->at(b - 1) == 1) ? true : false)

#define SETAS(a, b) aList->push_back((GETBC(a, b)))
