#pragma once
#include "SequenceD.h"
#include "Permutation.h"
#include <vector>

class KeyGen
{
public:
	KeyGen();
	KeyGen(SequenceD<64>);
	SequenceD<48> next();
	bool endStep();
	SequenceD<48> getKey(int);
private:
	int step;
	SequenceD<56> keyIPer;
	// The PC1 table
	int pc1[56] = {
	57,49,41,33,25,17,9, 
	1,58,50,42,34,26,18, 
	10,2,59,51,43,35,27, 
	19,11,3,60,52,44,36,		 
	63,55,47,39,31,23,15, 
	7,62,54,46,38,30,22, 
	14,6,61,53,45,37,29, 
	21,13,5,28,20,12,4 
	};
	vector<int> vec1;
	// The PC2 table
	int pc2[48] = { 
	14,17,11,24,1,5, 
	3,28,15,6,21,10, 
	23,19,12,4,26,8, 
	16,7,27,20,13,2, 
	41,52,31,37,47,55, 
	30,40,51,45,33,48, 
	44,49,39,56,34,53, 
	46,42,50,36,29,32 
	};
	vector<int> vec2;
	int leftShift[16] = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };

	vector<SequenceD<48>> keys;
};