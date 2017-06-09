#include "stdafx.h"

#define AS(a1, a2) answersList->at(a1)->at(a2)
#define AW(b1, b2) answersWeight->at(b1)->at(b2)
#define ASW(a1, a2, b1, b2)  AS(a1, a2) * AW(b1, b2);

static int WIGHT_NUM[8] = { 4, 6, 6, 4, 4, 5, 5, 2 };