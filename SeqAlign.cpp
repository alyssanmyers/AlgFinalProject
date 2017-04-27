/*******************************************************/
// Alyssa Myers & Luciano Mogorovic
// 3460:435 Algorithms
// Project 4 — DNA Sequence Alignment
// May 3, 2017
//
// Some description here!
/*******************************************************/

#include <string>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <cstdlib>
#include <fstream>

#include "ScoringMatrix.cpp"
#include "SeqAligner.cpp"

int main(int argc, char* argv[]){
  
    // check proper number of arguments
    if (argc == 3)
    {
        std::string seq1 = argv[1];
        std::string seq2 = argv[2];
        
        SeqAligner aligner(seq1, seq2);
        aligner.setCosts(-10, 1, -5);
        aligner.executeAlgorithm();
        aligner.getMatrix().printMatrix();
    }
    else
    {
        throw runtime_error("Invalid number of arguments!");
    }
    
    return 0;
}
