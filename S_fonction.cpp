#include "headers/S_fonction.h"
#include <iostream>

using namespace std;

S_fonction::S_fonction()
{
}

S_fonction::S_fonction(int table[8][4][16])
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 16; k++)
				substition_boxes[i][j][k] = table[i][j][k];
}

S_fonction::S_fonction(const S_fonction& box)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 16; k++)
				substition_boxes[i][j][k] = box.substition_boxes[i][j][k];
}

Sequence S_fonction::operator()(Sequence seqI)
{
	list<Sequence> listSeqO;

	for (int i = 0, j = 0; i < 8; i++, j = j + 6) {
		Sbox sbox(substition_boxes[i]);
		Sequence seqO = sbox(seqI.sous_sequence(j, j + 5));
		listSeqO.push_back(seqO);
	}

	Sequence SeqOs(listSeqO);
	return SeqOs;
}

S_fonction::~S_fonction()
{
	// delete[] substitution;
}