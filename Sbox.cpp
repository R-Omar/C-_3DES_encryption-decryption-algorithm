#include "headers/Sbox.h"
#include <iostream>

using namespace std;

Sbox::Sbox(int table[4][16])
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 16; j++)
			substitution[i][j] = table[i][j];
}

Sbox::Sbox(const Sbox& box)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 16; j++)
			substitution[i][j] = box.substitution[i][j];
}

Sequence Sbox::operator()(Sequence seqI)
{
	Sequence seqO(4);
	int row = 2*seqI(0) + seqI(5);
	int column = 8*seqI(1) + 4*seqI(2) + 2*seqI(3) + seqI(4);
	seqO = substitution[row-1][column-1];
	return seqO;
}

Sbox::~Sbox()
{
	// delete[] substitution;
}
