#include "stdafx.h"
#include "Answers.h"

void Answers::setAnswersWeight(vector<vector<float> *> * answersWeight) {
	this->answersWeight = answersWeight;
}

void Answers::setAnswersList(vector<vector<int> *> * answersList) {
	this->answersList = answersList;
}

vector<float> * Answers::getResultChi() {
	return this->resultChi;
}

vector<float> * Answers::getResultEng() {
	return this->resultEng;
}

//太阳经输不利 = （题4A / B / C / D + 题5B / C）80%+（题7B）8%+（题9B）7%+（题11C）5%
//风寒痹阻 = （题8B）55%+（题8C）15%+（题13D）10%+（题15B）10%+（题15C）5%+（题6.1B / D）10%
//痰湿阻络 = （题8B）50%+（题8C）5%+（题11F）20%+（题9C）15%+（题13C）5%+（题15B / C）5%
//肝气郁结 = （题8D）65%+（题11B）15%+（题12B / C）15%+（题6.1）5%
//气血亏虚 = （题11G）30%+（题13B）30%+（题9F）25%+（题12D）15%
//肝肾不足 = （题14B）25%+（题10B / C）25%+（题9E）20%+（题11D）20%+（题12B / C）10%
//肾阳虚 = （题14C）30%+（题15D）30%+（题12B / C）25%+（题8C）10%+（题13B）5%

//(6.1 -> 15; 6.2 -> 16; 6.3 -> 17);
// 7 -> 5; 8 -> 6; 9 -> 7; 10 -> 8; 11 -> 9; 12 -> 10; 13 -> 11; 14 -> 12; 15 -> 13;
// 6.1 -> 14; 6.2 -> 15; 6.3 -> 16
// a->0 b->1 c->2 d->3 e->4 f->5 g->6


void Answers::calculateAnswers() {
	float result = 0;
	resultChi = new vector<float>;
	resultEng = new vector<float>;
	// 太阳经输不利
	result = (AS(3, 0) | AS(3, 1) | AS(3, 2) | AS(3, 3) | AS(4, 1) | AS(4, 2)) * AW(0, 0);
	result += ASW(5, 1, 0, 1);
	result += ASW(7, 1, 0, 2);
	result += ASW(9, 2, 0, 3);
	resultChi->push_back(result);
	//风寒痹阻
	result = ASW(6, 1, 1, 0);
	result += ASW(6, 2, 1, 1);
	result += ASW(11, 3, 1, 2);
	result += ASW(13, 1, 1, 3);
	result += ASW(13, 2, 1, 4);
	result += (AS(14, 1) | AS(14, 3)) * AW(1, 5);
	resultChi->push_back(result);
	//痰湿阻络
	result = ASW(6, 1, 2, 0);
	result += ASW(6, 2, 2, 1);
	result += ASW(9, 5, 2, 2);
	result += ASW(7, 2, 2, 3);
	result += ASW(11, 2, 2, 4);
	result += (AS(13, 1) | AS(13, 2)) * AW(2, 5);
	resultChi->push_back(result);
	//肝气郁结
	result = ASW(6, 3, 3, 0);
	result += ASW(9, 1, 3, 1);
	result += (AS(10, 1) | AS(10, 2)) * AW(3, 2);
	result += (AS(14, 0) | AS(14, 1) | AS(14, 2) | AS(14, 3)) * AW(3, 3);
	resultChi->push_back(result);
	//气血亏虚
	result = ASW(9, 6, 4, 0);
	result += ASW(11, 1, 4, 1);
	result += ASW(7, 5, 4, 2);
	result += ASW(10, 3, 4, 3);
	resultChi->push_back(result);
	//肝肾不足
	result = ASW(12, 1, 5, 0);
	result += (AS(8, 1) | AS(8, 2)) * AW(5, 1);
	result += ASW(7, 4, 5, 2);
	result += ASW(9, 3, 5, 3);
	result += (AS(10, 1) | AS(10, 2)) * AW(5, 4);
	resultChi->push_back(result);
	//肾阳虚
	result = ASW(12, 2, 6, 0);
	result += ASW(13, 3, 6, 1);
	result += (AS(10, 1) | AS(10, 2)) * AW(6, 2);
	result += ASW(6, 2, 6, 3);
	result += ASW(11, 1, 6, 4);
	resultChi->push_back(result);

	//颈型
	result = resultChi->at(5);
	result += resultChi->at(4);
	result += ASW(6, 4, 7, 0);
	resultEng->push_back(result);
	//神经根型
	result = resultChi->at(1);
	result += resultChi->at(2);
	result += resultChi->at(4);
	resultEng->push_back(result);
	//脊髓型
	result = resultChi->at(5);
	result += resultChi->at(4);
	result += resultChi->at(6);
	resultEng->push_back(result);
	//交感神经型
	result = resultChi->at(0);
	result += resultChi->at(3);
	resultEng->push_back(result);
	//椎动脉型
	result = resultChi->at(5);
	resultEng->push_back(result);
	//食管压迫型
	result = ASW(9, 5, 7, 1);
	resultEng->push_back(result);
}