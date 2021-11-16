#include "headers/DESinv.h"
#include "headers/Permutation.h"

DESinv::DESinv(SequenceD<64> initialKey)
{
    finv = Finv(initialKey);
    vector<int> vectemp1(IP, IP + sizeof(IP) / sizeof(IP[0]));
    vec1 = vectemp1;
    vector<int> vectemp2(FP, FP + sizeof(FP) / sizeof(FP[0]));
    vec2 = vectemp2;
}

SequenceD<64> DESinv::operator()(SequenceD<64> seqI)
{
	//permutation initiale
    Permutation<64, 64> p;
    SequenceD<64> sequenceTmp = p(seqI, vec1);

    //16 rounds
    for (int i = 0; i < 16; i++){
        Sequence leftI = sequenceTmp.left();
        Sequence rightI = sequenceTmp.right();
        Sequence rightTmp = finv(rightI);  // operator() not working
        sequenceTmp = SequenceD<64>(rightI, leftI * rightTmp);
    }
    
    //32-bit swap
    sequenceTmp = SequenceD<64>(sequenceTmp.right(), sequenceTmp.left());

    //permutation finale
    SequenceD<64> sequenceF = p(sequenceTmp, vec2);
    return sequenceF;
}
