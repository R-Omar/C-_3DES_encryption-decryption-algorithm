#include "headers/KeyGen.h"


KeyGen::KeyGen()
{
}

KeyGen::KeyGen(SequenceD<64> keyI)
{
	step = 0;
    vector<int> vectmp1(pc1, pc1 + sizeof(pc1) / sizeof(pc1[0]));
    vector<int> vectmp2 (pc2, pc2 + sizeof(pc2) / sizeof(pc2[0]));
    vec1 = vectmp1;
    vec2 = vectmp2;
    Permutation<64, 56> perm;
	keyIPer = perm(keyI,vec1);
}

SequenceD<48> KeyGen::next()
{   
    keyIPer.decalage(leftShift[step]);
    Permutation<56, 48> perm;
    SequenceD<48> keyStep = perm(keyIPer, vec2);
    keys.push_back(keyStep);
    step++;
    return keyStep;
}

bool KeyGen::endStep()
{
	return step == 16;
}

SequenceD<48> KeyGen::getKey(int i)
{
    return keys[i];
}