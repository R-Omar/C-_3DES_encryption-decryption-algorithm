#include "headers/Sequence.h"

Sequence::Sequence()
{
	for (int i = 0; i < 4; i++) {
		int randomBit = rand() & 1;
		sequence.push_back(randomBit);
	}
}

Sequence::Sequence(int s)
{
	for (int i = 0; i < s; i++) {
		int randomBit = rand() & 1;
		sequence.push_back(randomBit);
	}
}

Sequence::Sequence(list<Sequence> seqs) 
{
	for(auto it = seqs.begin(); it != seqs.end(); ++it)//TODO A revoir
	{
		Sequence s = *it;
		for (auto e = s.sequence.begin(); e != s.sequence.end(); ++e) {
			int x = *e;
			sequence.push_back(x);
		}
	}
}

int& Sequence::operator[](int index)
{	
	if (index >= sequence.size()) {
		throw runtime_error("Sequence::operator[] - index non valide (trop grand)");
	}
	return sequence[index];
}

int Sequence::operator()(int index) const
{
	if (index >= sequence.size()) {
		throw runtime_error("Sequence::operator() - index non valide (trop grand)");
	}
	return sequence[index];
}

int Sequence::size()
{
	return (int)sequence.size();
}

void Sequence::operator=(int value)
{
	deque<int> tmpDeque;

	//on convertit en binaire
	while (value != 0) {
		value % 2 == 0 ? tmpDeque.push_front(0) : tmpDeque.push_front(1);
		value /= 2;
	}
	int diff = (int)tmpDeque.size() - (int)sequence.size();

	//on coupe en partant de la gauche si trop grand
	for (int i = 0; i < diff; i++) {
		tmpDeque.pop_front();
	}

	//on complète avec des 0 en partant de la gauche si trop petit 
	for (int i = 0; i < -diff; i++) {
		tmpDeque.push_front(0);
	}
	sequence = tmpDeque;
}

Sequence operator*(Sequence seq1, Sequence seq2)
{
	deque<int> tmpDeque;
	if (seq1.size() != seq2.size()) {
		throw runtime_error("operator* - tailles differentes pour les sequences");
	}
	for (int i = 0; i < seq1.size(); i++) {
		if (seq1(i) != seq2(i)) {
			tmpDeque.push_back(1);
		}
		else {
			tmpDeque.push_back(0);
		}
	}
	Sequence s = Sequence();
	s.sequence = tmpDeque;
	return s;
}

void Sequence::decalage(int shift)
{
	for (int i = 0; i < shift; i++) {
		int tmp = sequence.front();
		sequence.pop_front();
		sequence.push_back(tmp);
	}
}

Sequence Sequence::permutation(vector<int> vec)
{
	deque<int> tmpDeque;
	for (const auto& index : vec) {
		if (index > size()) {
			throw runtime_error("Sequence::permutation - valeur trop grande (out of bounds) dans le vector");
		}
		else {
			tmpDeque.push_back(sequence[index-1]);
		}

	}
	
	Sequence s = Sequence();
	s.sequence = tmpDeque;
	return s;
}

Sequence Sequence::sous_sequence(int a, int b)
{
	if (a > sequence.size() || b > sequence.size()) {
		throw runtime_error("Sequence::sous_sequence - L'un des indices est trop grand");
	}
	if (a < 0 || b < 0) {
		throw runtime_error("Sequence::sous_sequence - L'un des indices est negatif");
	}
	if (a > b) {
		throw runtime_error("Sequence::sous_sequence -l'argument a doit etre plus petit que b");
	}
	deque<int> tmpDeque;
	for (int i = a; i <= b; i++) {
		tmpDeque.push_back(sequence[i]);
	}
	Sequence s = Sequence();
	s.sequence = tmpDeque;
	return s;
}

Sequence::~Sequence()
{
}

void Sequence::printSequence()
{
	for (auto it = sequence.begin(); it != sequence.end(); ++it) {
		cout << ' ' << *it;
	}
	cout << '\n';
}


