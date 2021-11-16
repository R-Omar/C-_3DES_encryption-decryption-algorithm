#pragma once
#include "SequenceD.h"
#include <string>

using namespace std;
class Crypt
{
public:
	Crypt(SequenceD<64>, SequenceD<64>);
	void operator()(string);

private:
	SequenceD<64> key1;
	SequenceD<64> key2;

};

