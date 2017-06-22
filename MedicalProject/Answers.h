#include "stdafx.h"
#include "Result.h"

#pragma once

using namespace std;

class Result;

class Answers {
private:
	vector<vector<int> *> * answersList;
	vector<vector<float> *> * answersWeight;
	vector<float> * resultChi;
	vector<float> * resultEng;
	Result * result;

public:
	void setAnswersWeight(vector<vector<float> *> * answersWeight);
	void setAnswersList(vector<vector<int> *> * answersList);
	vector<float> * getResultChi();
	vector<float> * getResultEng();
	void calculateAnswers(void);
	vector<vector<int> *> * getAnswersList();
};