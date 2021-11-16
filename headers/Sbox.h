#pragma once
#include "Sequence.h"

using namespace std;

class Sbox
{
public:
	Sbox(int[4][16]);
	Sequence operator()(Sequence);
	Sbox(const Sbox&);
	~Sbox();
private:
	int substitution[4][16];
};

