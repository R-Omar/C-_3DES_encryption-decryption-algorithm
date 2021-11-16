#pragma once
#include <deque>
#include <list>

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>

using namespace std;

class Sequence
{
public:
	Sequence();
	Sequence(int);
	Sequence(list<Sequence>);

	int& operator[](int);     
	int operator()(int) const;
	friend Sequence operator*(Sequence, Sequence);
	void operator=(int);

	int size();
	void decalage(int);
	Sequence permutation(vector<int>);
	Sequence sous_sequence(int, int);
	
	~Sequence();
	void printSequence();
private:
	deque<int> sequence;
};


