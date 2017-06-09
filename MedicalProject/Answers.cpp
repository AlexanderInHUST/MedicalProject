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

//̫�����䲻�� = ����4A / B / C / D + ��5B / C��80%+����7B��8%+����9B��7%+����11C��5%
//�纮���� = ����8B��55%+����8C��15%+����13D��10%+����15B��10%+����15C��5%+����6.1B / D��10%
//̵ʪ���� = ����8B��50%+����8C��5%+����11F��20%+����9C��15%+����13C��5%+����15B / C��5%
//�������� = ����8D��65%+����11B��15%+����12B / C��15%+����6.1��5%
//��Ѫ���� = ����11G��30%+����13B��30%+����9F��25%+����12D��15%
//�������� = ����14B��25%+����10B / C��25%+����9E��20%+����11D��20%+����12B / C��10%
//������ = ����14C��30%+����15D��30%+����12B / C��25%+����8C��10%+����13B��5%

//(6.1 -> 15; 6.2 -> 16; 6.3 -> 17);
// a->0 b->1 c->2 d->3 e->4 f->5 g->6

void Answers::calculateAnswers() {
	float result = 0;
	resultChi = new vector<float>;
	resultEng = new vector<float>;
	// ̫�����䲻��
	result = (AS(3, 0) | AS(3, 1) | AS(3, 2) | AS(3, 3) | AS(4, 1) | AS(4, 2)) * AW(0, 0);
	result += ASW(6, 1, 0, 1);
	result += ASW(8, 1, 0, 2);
	result += ASW(10, 2, 0, 3);
	resultChi->push_back(result);
	//�纮����
	result = ASW(7, 1, 1, 0);
	result += ASW(7, 2, 1, 1);
	result += ASW(12, 3, 1, 3);
	result += ASW(14, 1, 1, 4);
	result += ASW(14, 2, 1, 5);
	result += (AS(15, 1) | AS(15, 3)) * AW(1, 6);
	resultChi->push_back(result);
	//̵ʪ����
	result = ASW(7, 1, 2, 0);
	result += ASW(7, 2, 2, 1);
	result += ASW(10, 5, 2, 2);
	result += ASW(8, 2, 2, 3);
	result += ASW(12, 2, 2, 4);
	result += (AS(14, 1) | AS(14, 2)) * AW(2, 5);
	resultChi->push_back(result);
	//��������
	result = ASW(7, 3, 3, 0);
	result += ASW(10, 1, 3, 1);
	result += (AS(11, 1) | AS(11, 2)) * AW(3, 2);
	result += (AS(15, 0) | AS(15, 1) | AS(15, 2) | AS(15, 3)) * AW(3, 3);
	resultChi->push_back(result);
	//��Ѫ����
	result = ASW(10, 6, 4, 0);
	result += ASW(12, 1, 4, 1);
	result += ASW(8, 5, 4, 2);
	result += ASW(11, 3, 4, 3);
	resultChi->push_back(result);
	//��������
	result = ASW(13, 1, 5, 0);
	result += (AS(9, 1) | AS(9, 2)) * AW(5, 1);
	result += ASW(8, 4, 5, 2);
	result += ASW(10, 3, 5, 3);
	result += (AS(11, 1) | AS(11, 2)) * AW(5, 4);
	resultChi->push_back(result);
	//������
	result = ASW(13, 2, 6, 0);
	result += ASW(14, 3, 6, 1);
	result += (AS(11, 1) | AS(11, 2)) * AW(6, 2);
	result += ASW(7, 2, 6, 3);
	result += ASW(12, 1, 6, 4);
	resultChi->push_back(result);

	//����
	result = resultChi->at(5);
	result += resultChi->at(4);
	result += ASW(7, 4, 7, 0);
	resultEng->push_back(result);
	//�񾭸���
	result = resultChi->at(1);
	result += resultChi->at(2);
	result += resultChi->at(4);
	resultEng->push_back(result);
	//������
	result = resultChi->at(5);
	result += resultChi->at(4);
	result += resultChi->at(6);
	resultEng->push_back(result);
	//��������
	result = resultChi->at(0);
	result += resultChi->at(3);
	resultEng->push_back(result);
	//׵������
	result = resultChi->at(5);
	resultEng->push_back(result);
	//ʳ��ѹ����
	result = ASW(10, 5, 7, 1);
	resultEng->push_back(result);
}