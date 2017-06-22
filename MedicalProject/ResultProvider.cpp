#include "stdafx.h"
#include "ResultProvider.h"

void ResultProvider::calResult(vector<vector<int> *> * answersList, vector<vector<float> *> * weightList) {
	answer = new Answers;
	result = new Result;
	answer->setAnswersList(answersList);
	answer->setAnswersWeight(weightList);
	answer->calculateAnswers();
	result->setResultChi(answer->getResultChi());
	result->setResultEng(answer->getResultEng());
}

Result * ResultProvider::getResult() {
	return result;
}

Answers * ResultProvider::getAnswer() {
	return answer;
}