#include "stdafx.h"
#include "ResultPair.h"
#include <algorithm>

using namespace std;

class Result{
private:
	vector<ResultPair *> * resultChi;
	vector<ResultPair *> * resultEng;
	vector<ResultPair *> * sortedResultChi;
	vector<ResultPair *> * sortedResultEng;

	void sortResultChi();
	void sortResultEng();
public:
	void setResultChi(vector<float> * chiList);
	void setResultEng(vector<float> * engList);

	vector<ResultPair *> * getResultChi();
	vector<ResultPair *> * getResultEng();
	vector<ResultPair *> * getSortedResultChi();
	vector<ResultPair *> * getSortedResultEng();
};