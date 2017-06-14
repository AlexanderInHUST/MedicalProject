#include "stdafx.h"
#include "Answers.h"
#include "Result.h"

#pragma once

class ResultProvider{
protected:
	Answers * answer;
	Result * result;

public:
	void calResult(vector<vector<int> *> * answersList, vector<vector<float> *> * weightList);
	Result * getResult();
};