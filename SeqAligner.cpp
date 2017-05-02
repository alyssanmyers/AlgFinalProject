/*************************************************************/
// Alyssa Myers & Luciano Mogorovic
// 3460:435 Algorithms
// Project 4 — DNA Sequence Alignment
// May 5, 2017
//
// Comparing two sequences using dynamic programming algorithm.
/*************************************************************/

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

enum class Direction
{
    DIAGONAL,
    LEFT,
    ABOVE
};

class SeqAligner
{
private:
    
    ScoringMatrix cost_matrix;
    int gap, match, mismatch;
    string sequence1, sequence2;
    
    // computes the cost of a single cell in the matrix
    int computeCellCost(int, int);
    
    // finds the lowest costing cell while tracing back
    void findLowestCell(int*, int*, Direction*);
    
    // traces back through the matrix
    void traceBack(string*, string*);
    
public:
    
    string aligned_sequence1, aligned_sequence2;
    
    SeqAligner(string, string);
    
    // retrieves the matrix
    ScoringMatrix getMatrix();
    
    // sets the values for gaps, matches, and mismatches
    void setCosts(int, int, int);
    
    // runs the sequence alignment dynamic programming algorithm
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
    for (int j = 1; j < cost_matrix.getHeight(); j++)
    {
        for (int i = 1; i < cost_matrix.getWidth(); i++)
        {
            int new_value = computeCellCost(i, j);
            cost_matrix.setValue(i, j, new_value);
        }
    }
    
    traceBack(&aligned_sequence1, &aligned_sequence2);
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

    return max ( max (case1, case2), case3);
}

void SeqAligner::findLowestCell(int *i, int *j, Direction *dir)
{
    int* position;
    int diagonal, left, top;
    char s1, s2;
    
    // retrieves the current value
    int current_value = cost_matrix.getValue(*i, *j);
    
    if (*i > 0 && *j > 0)
    {
        diagonal = cost_matrix.getValue(*i - 1, *j - 1);
    }
    if (*i > 0)
    {
        left = cost_matrix.getValue(*i - 1, *j);
    }
    if (*j > 0)
    {
        top = cost_matrix.getValue(*i, *j - 1);
    }
    
    s1 = sequence1.at(*i);
    s2 = sequence2.at(*j);

    if (diagonal + (s1 == s2 ? match : mismatch) == current_value)
    {
        *i = *i - 1;
        *j = *j - 1;
        *dir = Direction::DIAGONAL;
    }
    else if (left + gap == current_value)
    {
        *i = *i - 1;
        *dir = Direction::LEFT;
    }
    else if (top + gap == current_value)
    {
        *j = *j - 1;
        *dir = Direction::ABOVE;
    }
}

void SeqAligner::traceBack(string *seq1, string *seq2)
{
    int i = cost_matrix.getWidth() - 1;
    int j = cost_matrix.getHeight() - 1;
    
    while (i > 0 || j > 0)
    {
        Direction dir;
        string t1 = "", t2 = "";
        t1 = sequence1.at(i);
        t2 = sequence2.at(j);
        
        findLowestCell(&i, &j, &dir);
        
        if (dir == Direction::DIAGONAL)
        {
            seq1->append(t1);
            seq2->append(t2);
        }
        else if (dir == Direction::LEFT)
        {
            seq1->append(t1);
            seq2->append("-");
        }
        else if (dir == Direction::ABOVE)
        {
            seq1->append("-");
            seq2->append(t2);
        }
        
    }
    
    reverse (seq1->begin(), seq1->end());
    reverse (seq2->begin(), seq2->end());
}







