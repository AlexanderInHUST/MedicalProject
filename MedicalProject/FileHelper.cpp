#include "stdafx.h"
#include "FileHelper.h"

vector<vector<float> *> * FileHelper::getWeight(string fileName) {
	FILE * file;
	vector<vector<float> *> * weight = new vector<vector<float> *>;
	file = fopen(fileName.c_str(), "r");
	for (int i = 0; i < 9; i++) {
		vector<float> * newOne = new vector<float>;
		for (int j = 0; j < WIGHT_NUM[i]; j++) {
			float w;
			fscanf(file, "%f", &w);
			newOne->push_back(w);
		}
		weight->push_back(newOne);
		fscanf(file, "\n");
	}
	fclose(file);
	return weight;
}