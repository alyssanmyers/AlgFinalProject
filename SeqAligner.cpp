/*******************************************************/
// Alyssa Myers & Luciano Mogorovic
// 3460:435 Algorithms
// Project 4 — DNA Sequence Alignment
// May 3, 2017
//
// Some description here!
/*******************************************************/

#include <string>
#include <vector>

using namespace std;

class SeqAligner
{
private:
    
    ScoringMatrix cost_matrix;
    
public:
    
    SeqAligner(string, string);
    
    ScoringMatrix getMatrix();
    
    ScoringMatrix executeAlgorithm();
};

SeqAligner::SeqAligner(string sequence1, string sequence2)
{
    cost_matrix = ScoringMatrix(sequence1, sequence2);
}

ScoringMatrix SeqAligner::getMatrix()
{
    return cost_matrix;
}




