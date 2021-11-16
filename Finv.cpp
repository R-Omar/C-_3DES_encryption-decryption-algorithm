#include "headers/Finv.h"

Finv::Finv()
{
}

Finv::Finv(SequenceD<64> seqD)
{
    keygen = KeyGen(seqD);
    s_fonction = S_fonction(substition_boxes);
    vector<int> vectmp1(ET, ET + sizeof(ET) / sizeof(ET[0]));
    v = vectmp1;
    vector<int> vectmp2(permutation_tab, permutation_tab + sizeof(permutation_tab) / sizeof(permutation_tab[0]));
    permTab = vectmp2;
    while (!keygen.endStep()) {
        keygen.next();
    }
    round = 15;
}

Sequence Finv::operator()(Sequence s)
{
    //step : expansion/permutation
    Sequence tmpSequence = s.permutation(v);

    //step : xor avec cl� K
    SequenceD<48> s48(tmpSequence);
    SequenceD<48> result = s48 * keygen.getKey(round);
    round--;

    //step : sboxes
    //sous-step : transformer la sequenceD<64> en sequence
    list<Sequence> list;
    list.push_back(result.left());
    list.push_back(result.right());
    Sequence resultXorSeq(list);
    //sous-step : appliquer la s-fonction
    Sequence seqO(32);
    seqO = s_fonction(resultXorSeq);

    //step : permutation
    return seqO.permutation(permTab);
}


