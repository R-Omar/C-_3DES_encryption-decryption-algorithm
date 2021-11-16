#pragma once
#include "SequenceD.h"
#include <string>
#include <vector>

using namespace std;

class FileOperations
{
public:
	string stringToBinary(string);
	void binaryToString(vector<SequenceD<64>>, string);
};