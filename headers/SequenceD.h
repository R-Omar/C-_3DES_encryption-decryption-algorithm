#pragma once
#include "Sequence.h"
#include <iostream>
#include <deque>


using namespace std;

template <int n>
class SequenceD 
{
public:
	SequenceD();
	SequenceD(Sequence, Sequence);
	SequenceD(Sequence);
	int &operator[](int);
	int operator()(int) const;
	int size();
	void decalage(int);
	Sequence right();
	Sequence left();
	void printSequence();

	template <int x>
	friend SequenceD<x> operator*(SequenceD<x>, SequenceD<x>);

	friend ostream& operator<<(ostream&, SequenceD<64>&);
	friend void operator>>(istream&,SequenceD<64>&);
	friend void write(ostream&, SequenceD<64>&);
	friend void read(istream&, SequenceD<64>&);
	template<class T> friend void affichage(T);

private:
	Sequence leftSeq;
	Sequence rightSeq;
};

template <int n>
SequenceD<n>::SequenceD()
{
	if (n % 2 != 0)
	{
		throw runtime_error("SequenceD::SequenceD() - la taille n'est pas un multiple de 2");
	}
	else
	{
		leftSeq = Sequence(n / 2);
		rightSeq = Sequence(n / 2);
	}
}

template <int n>
void SequenceD<n>::printSequence()
{
	for (int i = 0; i < leftSeq.size(); i++)
	{
		cout << ' ' << leftSeq(i);
	}
	cout << ' ';
	for (int i = 0; i < rightSeq.size(); i++)
	{
		cout << ' ' << rightSeq(i);
	}
	cout << '\n';
}

template <int n>
SequenceD<n>::SequenceD(Sequence s1, Sequence s2)
{
	if (s1.size() != s2.size())
	{
		throw runtime_error("SequenceD::SequenceD(s1,s2) - tailles differentes des sequences");
	}

	else if (s1.size() != n / 2)
	{
		throw runtime_error("SequenceD::SequenceD(s1,s2) - taille des sequences differentes de la taille de la sequenceD");
	}
	else
	{
		leftSeq = s1;
		rightSeq = s2;
	}
}

template <int n>
SequenceD<n>::SequenceD(Sequence s)
{
	if (s.size() % 2 != 0)
	{
		throw runtime_error("SequenceD::SequenceD(s) - Sequence de taille impaire");
	}
	else
	{
		leftSeq = Sequence(s.size()/2);
		rightSeq = Sequence(s.size()/2);
		for (int i = 0; i < s.size()/2; i++){
			leftSeq[i] = s(i);
		}
		for (int i = s.size()/2; i < s.size(); i++){
			rightSeq[i-s.size()/2] = s(i);
		}
	}
}

template <int n>
int SequenceD<n>::size()
{
	return n;
}

template <int n>
void SequenceD<n>::decalage(int d)
{
	leftSeq.decalage(d);
	rightSeq.decalage(d);
}

template <int n>
Sequence SequenceD<n>::left()
{
	return leftSeq;
}

template <int n>
Sequence SequenceD<n>::right()
{
	return rightSeq;
}

template <int n>
int &SequenceD<n>::operator[](int index)
{
	if (index >= n)
	{
		throw runtime_error("SequenceD<n>::operator[] - index non valide");
	}
	else if (index < n / 2)
		return leftSeq[index];
	else if (index >= n / 2)
		return rightSeq[index - n / 2];
	return leftSeq[0];
}

template <int n>
int SequenceD<n>::operator()(int index) const
{
	if (index >= n)
	{
		throw runtime_error("SequenceD<n>::operator[] - index non valide");
	}
	else if (index < n / 2)
		return leftSeq(index);
	else if (index >= n / 2)
		return rightSeq(index - n / 2);
	return leftSeq(0);
}

template <int n>
SequenceD<n> operator*(SequenceD<n> s1, SequenceD<n> s2)
{
		if (s1.size() != s2.size())
		{
			throw runtime_error("tailles differentes des sequences");
		}
		SequenceD<n> result;
		result.rightSeq = s1.rightSeq * s2.rightSeq;
		result.leftSeq = s1.leftSeq * s2.leftSeq;
		return result;
}

template<class T>
void affichage(T seq) {
	for (int i = 0; i < seq.size(); i++) {
		cout << seq(i);
	}
}