/*************************************************************/
// Alyssa Myers & Luciano Mogorovic
// 3460:435 Algorithms
// Project 4 — DNA Sequence Alignment
// May 3, 2017
//
// Comparing two sequences using dynamic programming algorithm.
/*************************************************************/

#include <string>
#include <iostream>

#include "ScoringMatrix.cpp"
#include "SeqAligner.cpp"

int main(int argc, char* argv[]){
  
    // check proper number of arguments
    if (argc == 3)
    {
        std::string seq1 = argv[1];
        std::string seq2 = argv[2];
        
        std::string aligned_sequence1;
        std::string aligned_sequence2;
        std::cout<<"before aligner."<<std::endl;
        SeqAligner aligner(seq1, seq2);
        std::cout<<"after aligner."<<std::endl;
        aligner.setCosts(-1, 1, 0);
        std::cout<<"after set costs."<<std::endl;
        aligner.executeAlgorithm();
        std::cout<<"after algorithm."<<std::endl;
        
        aligned_sequence1 = aligner.aligned_sequence1;
        aligned_sequence2 = aligner.aligned_sequence2;
        std::cout << aligned_sequence1 << std::endl << aligned_sequence2 << std::endl;
        aligner.getMatrix().printMatrix();
    }
    else
    {
        throw runtime_error("Invalid number of arguments!");
    }
    
    return 0;
}
