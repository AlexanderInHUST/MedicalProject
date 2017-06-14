#include "stdafx.h"
#include "Result.h"

bool sortFunction(const ResultPair * v1, const ResultPair * v2) {
	return v1->value < v2->value;
}

void Result::setResultChi(vector<float> * chiList) {
	resultChi = new vector<ResultPair *>;
	wstring names[7] = { L"太阳经输不利", L"风寒痹阻", L"痰湿阻络", L"肝气郁结", L"气血亏虚", L"肝肾不足", L"肾阳虚" };
	for (int i = 0; i < 7; i++) {
		ResultPair * newOne = new ResultPair;
		newOne->kind = new wstring(names[i]);
		newOne->value = chiList->at(i);
		resultChi->push_back(newOne);
	}
	sortResultChi();
}

void Result::sortResultChi() {
	sortedResultChi = new vector<ResultPair *>;
	sortedResultChi->insert(sortedResultChi->end(), resultChi->begin(), resultChi->end());
	sort(sortedResultChi->begin(), sortedResultChi->end(), sortFunction);
}

void Result::setResultEng(vector<float> * engList) {
	resultEng = new vector<ResultPair *>;
	wstring names[6] = { L"颈型", L"神经根型", L"脊髓型", L"交感神经型", L"椎动脉型", L"食管压迫型" };
	for (int i = 0; i < 6; i++) {
		ResultPair * newOne = new ResultPair;
		newOne->kind = new wstring(names[i]);
		newOne->value = engList->at(i);
		resultEng->push_back(newOne);
	}
}

void Result::sortResultEng() {
	sortedResultEng = new vector<ResultPair *>;
	sortedResultEng->insert(sortedResultEng->end(), resultEng->begin(), resultEng->end());
	sort(sortedResultEng->begin(), sortedResultEng->end(), sortFunction);
}

vector<ResultPair *> * Result::getSortedResultChi() {
	return sortedResultChi;
}

vector<ResultPair *> * Result::getSortedResultEng() {
	return sortedResultEng;
}