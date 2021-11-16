#include "headers/SequenceD.h"
#include <sstream>
#include <bitset>

ostream& operator<<( ostream& os ,  SequenceD<64>& seqD) {

    string data = "";
    for (int i = 0 ; i < seqD.size(); i++ )
        data.append(to_string(seqD(i)));
    
    // from stackoverflow https://stackoverflow.com/questions/23344257/convert-a-string-of-binary-into-an-ascii-string-c
    stringstream sstream(data);
    string output;
    while(sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }
    os << output;
    return os;
}

void operator>>(istream& is,SequenceD<64>& seqD) {
    string data;
    is >> data;

    for (int i = 0, j = 0; i < data.length(); i++, j = j+8) {
        bitset<8> bs(data[i]);
        for (int k = 0 ; k < 8 ; k++ )
            seqD[j + k ] = bs[ 7 - k];
    }
}

void write(ostream& os, SequenceD<64>& seqD) {
    string data = "";
    for (int i = 0 ; i < seqD.size(); i++ )
        data.append(to_string(seqD(i)));
    os << data;
 }

 void read(istream& is, SequenceD<64>& seqD) {
 	string data;
    is >> data;
    if (data.length() > 64) {
        throw runtime_error("read() :: Le istream fait plus de 64 bits");
    }
 	for (int i = 0 ; i < data.length(); i++) {
 	    seqD[i] = data[i] - '0';
    }
    for (int i = 0; i < 64 - data.length(); i++) {
        seqD[(int)data.length() + i] = 0;
    }
 }
