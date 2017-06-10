#include "stdafx.h"

using namespace std;

static int WIGHT_NUM[8] = { 4, 6, 6, 4, 4, 5, 5, 2 };

class FileHelper{
public:
	vector<vector<float> *> * getWeight(string fileName);
};