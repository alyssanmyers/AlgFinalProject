#include <string>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <cstdlib>
#include <fstream>

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

    int Matrix[seq1L][seq2L];

    int gap = -2;
    int match = 1;
    int nmatch = -1;

    // set up first row with gap value
    for(int i = 0; i < seq2L; ++i){

        Matrix[0][i] = i * gap;

    }

    // set up first column with gap value
    for(int i = 0; i < seq1L; ++i){

        Matrix[i][0] = i * gap;
        
    }

    for(int i = 0; i < seq2L; ++i){
        std::cout << Matrix[0][i];
    }
    std::cout  << "\n";
    for(int i = 0; i < seq2L; ++i){
        std::cout << Matrix[i][0] << "\n";
    }
*/

}
