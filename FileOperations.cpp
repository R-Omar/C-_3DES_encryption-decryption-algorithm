#include "headers/FileOperations.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <bitset>

string FileOperations::stringToBinary(string filename)
{
    fstream file;
    file.open(filename, ios::in);
    if (file) {
        stringstream buffer;
        buffer << file.rdbuf();
        string textfile = buffer.str();
        
        // string output;
        // file.close();
        // //convert into binary
        // for (int i = 0; i < textfile.size(); i++)
        // {
        //     string binaryConversion;
        //     for (int j = 7; j >= 0; --j) {
        //         binaryConversion += ((textfile[i] & (1 << j)) ? '1' : '0');
        //     }
        //     output += binaryConversion;
        // }
        // return output;
        
        return textfile;
    }
    else {
        throw runtime_error("Couldn't open the file " + filename);
    }
}

void FileOperations::binaryToString(vector<SequenceD<64>> listSeqD, string filename)
{
    //convert back to char
    string data = "";
    for (int s = 0; s < listSeqD.size(); s++) {
        SequenceD<64> seq = listSeqD[s];
        for (int b = 0; b < seq.size(); b++) {
            data.append(to_string(seq(b)));
        }
    }

    // //// from stackoverflow https://stackoverflow.com/questions/23344257/convert-a-string-of-binary-into-an-ascii-string-c
    // stringstream sstream(data);
    // string encrypted_output;
    // int i = 1;
    // while (sstream.good())
    // {
    //     bitset<8> bits;
    //     sstream >> bits;
    //     char c = char(bits.to_ulong());
    //     encrypted_output += c;
    //     i++;
    // }

    //encrypted_output.pop_back();
    //cout << encrypted_output;
    //cout << "\n";

    // write to a file
    ofstream outfile;
    outfile.open(filename);
    outfile << data;
    // outfile << encrypted_output;
    outfile.close();
}