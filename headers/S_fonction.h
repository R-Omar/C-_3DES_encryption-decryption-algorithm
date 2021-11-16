#pragma once
#include "Sequence.h"
#include "Sbox.h"

using namespace std;

class S_fonction
{
public:
	S_fonction();
	S_fonction(int[8][4][16]);
	Sequence operator()(Sequence);
	S_fonction(const S_fonction&);
	~S_fonction();
private:
	int substition_boxes[8][4][16];
};