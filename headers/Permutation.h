#pragma once
#include "SequenceD.h"

using namespace std;

template <int x, int y>
class Permutation
{
public:
    SequenceD<y> operator()(SequenceD<x>,vector<int>);
};

template<int x, int y>
SequenceD<y> Permutation<x, y>::operator()(SequenceD<x> seqD, vector<int> vec)
{
    SequenceD<y> temp;
    for (int i = 0; i < y; i++) {
        if (vec[i] > seqD.size()) {
            throw runtime_error("Permutation::operator() - valeur trop grande (out of bounds) dans le vector");
        }
        temp[i] = seqD[vec[i] - 1];
    }
    return temp;
}
