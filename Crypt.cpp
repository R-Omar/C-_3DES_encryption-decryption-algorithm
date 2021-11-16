#include "headers/Crypt.h"
#include "headers/DES.h"
#include "headers/DESinv.h"
#include <vector>
#include "headers/FileOperations.h"

Crypt::Crypt(SequenceD<64> k1, SequenceD<64> k2)
{
    key1 = k1;
    key2 = k2;
}

void Crypt::operator()(string filename)
{
    FileOperations fo;
    string output = fo.stringToBinary(filename);

    //Convert into 64-bit chunk
    vector<SequenceD<64>> listSeqD;
    int compt = 0;
    SequenceD<64> tmpSeq = SequenceD<64>();
    for (int i = 0; i < output.length(); i++) {
        compt++;
        string tmp = output.substr(i, 1);
        int binaire = stoi(tmp);
        tmpSeq[compt - 1] = binaire;
        if (compt % 64 == 0 || i == output.length() - 1) {
            for (int j = 0; j < 64 - compt; j++) {
                tmpSeq[compt + j] = 0;
            }
            DES des1(key1);
            DES des2(key1);
            DESinv desinv1(key2);
            SequenceD<64> tripleDES = des2(desinv1(des1(tmpSeq)));
            listSeqD.push_back(tripleDES);
            compt = 0;
        }
    }

    fo.binaryToString(listSeqD, "encrypted_"+filename);
}
