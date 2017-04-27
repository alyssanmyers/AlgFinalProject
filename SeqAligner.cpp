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
#include <cmath>

using namespace std;

class SeqAligner
{
private:
    
    ScoringMatrix cost_matrix;
    int gap, match, mismatch;
    string sequence1, sequence2;
    
    // returns
    
    // computes the cost of a single cell in the matrix
    int computeCellCost(int, int);
    
public:
    
    SeqAligner(string, string);
    
    ScoringMatrix getMatrix();
    
    // sets the values for gaps, matches, and mismatches
    void setCosts(int, int, int);
    
    void executeAlgorithm();
};

SeqAligner::SeqAligner(string sequence1, string sequence2)
{
    this->sequence1 = sequence1.insert (0, 1, ' ');
    this->sequence2 = sequence2.insert (0, 1, ' ');
    
    cost_matrix = ScoringMatrix(this->sequence1, this->sequence2);
}

ScoringMatrix SeqAligner::getMatrix()
{
    return cost_matrix;
}

void SeqAligner::setCosts(int gap, int match, int mismatch)
{
    this->gap = gap;
    this->match = match;
    this->mismatch = mismatch;
    
    cost_matrix.generateFirstRC(gap);
}

void SeqAligner::executeAlgorithm()
{
    cost_matrix.setValue(1, 1, computeCellCost(1, 1));
    cost_matrix.setValue(2, 1, computeCellCost(2, 1));
}

int SeqAligner::computeCellCost(int i, int j)
{
    int diagonal, left, top;
    char s1, s2;
    int case1, case2, case3;
    
    diagonal = cost_matrix.getValue(i - 1, j - 1);
    left = cost_matrix.getValue(i - 1, j);
    top = cost_matrix.getValue(i, j - 1);
    
    s1 = sequence1.at(i);
    s2 = sequence2.at(j);
    
    case1 = diagonal + (s1 == s2 ? match : mismatch);
    case2 = left + gap;
    case3 = top + gap;
    /*
    cout << "Case 1: " << diagonal << " + " << (s1 == s2 ? match : mismatch) << endl
    << "Case 2 : " << left << " + " << gap << endl
    << "Case 3 : " << top << " + " << gap << endl;
    
    cout << "seq1 : " << s1 << "\nseq2: " << s2 << endl;
    */
    return max ( max (case1, case2), case3);
}











