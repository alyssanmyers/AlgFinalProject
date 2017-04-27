#include <string>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <cstdlib>
#include <fstream>

int main(int argc, char *argv[])
{

    // get the 2 sequences from command line
    std::string seq1(argv[1]);
    std::string seq2(argv[2]);

    // get the two lengths of the sequences
    int seq1L = seq1.length();
    int seq2L = seq2.length();

#include "ScoringMatrix.cpp"


int main(int argc, char* argv[]){
    
    std::string seq1 = argv[1];
    std::string seq2 = argv[2];
    
    ScoringMatrix matrix(seq1, seq2);
    matrix.setCosts(-2, 1, -1);
    matrix.printMatrix();
    
/*
    int seq1L = seq1.length() + 1;
    int seq2L = seq2.length() + 1;

    // set up a matrix of appropratie size
    int Matrix[seq1L][seq2L];

    // set values for each possibility
    int gap = -2;
    int match = 1;
    int nmatch = -1;

    // set up first row with gap value
    for (int i = 0; i < seq2L; ++i)
    {

        Matrix[0][i] = i * gap;
    }

    // set up first column with gap value
    for (int i = 0; i < seq1L; ++i)
    {

        Matrix[i][0] = i * gap;
    }

    // fill the matrix
    for (int i = 0; i < seq1L; ++i)
    {

        for (int j = 0; j < seq2L; ++j)
        {
            int sim;
            if (seq1[i] == seq2[j])
                sim = match;
            else
                sim = nmatch;
            int diag, left, above;
            diag = Matrix[i - 1][j - 1] + sim;
            left = Matrix[i][j - 1] + gap;
            above = Matrix[i][j - 1] + gap;

            int fMax = diag >= left ? diag : left;
            int max = above >= fMax ? above : fMax;

            if (max == diag)
                Matrix[i][j] = diag;
            else if (max == left)
                Matrix[i][j] = left;
            else if (max == above)
                Matrix[i][j] = above;
        }

    for(int i = 0; i < seq2L; ++i){
        std::cout << Matrix[0][i];
    }
    std::cout  << "\n";
    for(int i = 0; i < seq2L; ++i){
        std::cout << Matrix[i][0] << "\n";
    }
*/

    for (int i = 0; i < seq2L; ++i)
    {
        for (int j = 0; j < seq1L; ++j)
        {
            std::cout << Matrix[j][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
