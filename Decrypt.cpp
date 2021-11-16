#include "headers/Decrypt.h"
#include "headers/DES.h"
#include "headers/DESinv.h"
#include <vector>
#include "headers/FileOperations.h"

Decrypt::Decrypt(SequenceD<64> k1, SequenceD<64> k2)
{
    key1 = k1;
    key2 = k2;
}

void Decrypt::operator()(string filename)
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
            DESinv desinv1(key1);
            DESinv desinv2(key1);
            DES des1(key2);
            SequenceD<64> tripleDES = desinv2(des1(desinv1(tmpSeq)));
            listSeqD.push_back(tripleDES);
            compt = 0;
        }
    }
    string tmp = filename.substr(0, filename.find("_"));
    fo.binaryToString(listSeqD, "decrypted_"+ filename.substr(filename.find("_")+1, filename.length()-tmp.length()));
}