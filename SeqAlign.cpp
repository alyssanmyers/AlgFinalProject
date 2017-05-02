/*************************************************************/
// Alyssa Myers & Luciano Mogorovic
// 3460:435 Algorithms
// Project 4 — DNA Sequence Alignment
// May 5, 2017
//
// Comparing two sequences using dynamic programming algorithm.
/*************************************************************/

#include <string>
#include <iostream>

#include "ScoringMatrix.cpp"
#include "SeqAligner.cpp"

#define GAP -1
#define MATCH 1
#define MISMATCH 0

void checkInput(string *);

int main(int argc, char* argv[])
{
    std::string seq1 = argv[1];
    std::string seq2 = argv[2];
    
    // check for appropriate chars
    checkInput(&seq1);
    checkInput(&seq2);
    
    // check proper number of arguments
    if (argc == 3)
    {
        std::string aligned_sequence1;
        std::string aligned_sequence2;
        
        SeqAligner aligner(seq1, seq2);
        aligner.setCosts(GAP, MATCH, MISMATCH);
        aligner.executeAlgorithm();
        
        aligned_sequence1 = aligner.aligned_sequence1;
        aligned_sequence2 = aligner.aligned_sequence2;
        std::cout << aligned_sequence1 << std::endl << aligned_sequence2 << std::endl;
        aligner.getMatrix().printMatrix();
        
        if(aligner.getMatrix().getScore() <= 0){
            std::cout << "No relation" << std::endl;
        }
        else if(seq1.length() == seq2.length()){
            double percent = (double)(aligner.getMatrix().getScore())/seq1.length();
            std::cout << "Percent Related: " << percent*100 << "%" << std::endl;
        }
        else if(seq1.length() != seq2.length()){
            int length = seq1.length() < seq2.length() ? seq1.length() : seq2.length();
            double percent = (double)(aligner.getMatrix().getScore())/length;
            std::cout << "Percent Related: " << percent*100 << "%" << std::endl;
        }
    }
    else
    {
        throw runtime_error("Invalid number of arguments!");
    }
    
    return 0;
}

void checkInput(string *sequence)
{
    for (int i = 0; i < sequence->length(); i++)
    {
        char temp = toupper(sequence->at(i));
        if ( (temp != 'A') && (temp != 'T') && (temp != 'C') && (temp != 'G') )
        {
            string err = "Invalid argument type! (a/t/c/g) : ";
            err += temp;
            throw runtime_error(err);
        }
    }
}
