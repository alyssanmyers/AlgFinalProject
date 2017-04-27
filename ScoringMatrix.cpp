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

class ScoringMatrix
{
private:
    unsigned int width, height;
    int gap, match, mismatch;
    string sequence1, sequence2;
    vector<vector<int>> matrix;
    
public:
    
    // constructs a new matrix
    ScoringMatrix();
    ScoringMatrix(string, string);
    
    // sets the values for gaps, matches, and mismatches
    void setCosts(int, int, int);
    
    // retrieves the width
    unsigned int getWidth();
    
    // sets the width
    void setWidth(unsigned int&);
    
    // retrieves the height
    unsigned int getHeight();
    
    // sets the height
    void setHeight(unsigned int&);
    
    // retrieves value at given location
    int getValue(unsigned int, unsigned int);
    
    // sets the value at given location
    void setValue(const unsigned int&, const unsigned int&, const int& value);
    
    // prints the matrix
    void printMatrix();
};

ScoringMatrix::ScoringMatrix()
{
    width = 0;
    height = 0;
    
    matrix[0][0];
}

ScoringMatrix::ScoringMatrix(string sequence1, string sequence2)
{

    this->sequence1 = sequence1;
    this->sequence2 = sequence2;
    
    width = sequence1.length() + 1;
    height = sequence2.length() + 1;
    
    matrix.resize(width);
    for (auto& entry : matrix)
    {
        entry.resize(height);
    }
}

void ScoringMatrix::setCosts(int gap, int match, int mismatch)
{
    this->gap = gap;
    this->match = match;
    this->mismatch = mismatch;
    
    // set up the first row with gap value
    for (int i = 0; i < sequence1.length() + 1; i++)
    {
        matrix[0][i] = i * gap;
    }
    
    // set up the first column with gap value
    for (int i = 0; i < sequence2.length() + 1; i++)
    {
        matrix[i][0] = i * gap;
    }
}

unsigned int ScoringMatrix::getWidth()
{
    return width;
}

void ScoringMatrix::setWidth(unsigned int& width)
{
    this->width = width;
    
    matrix.resize(width, vector<int>(height));
}

unsigned int ScoringMatrix::getHeight()
{
    return height;
}

void ScoringMatrix::setHeight(unsigned int& height)
{
    this->height = height;
    
    for (auto& entry : matrix)
    {
        entry.resize(height);
    }
}

int ScoringMatrix::getValue(unsigned int x, unsigned int y)
{
    if (x >= width)
    {
        string err = "X coordinate (" + to_string(x) + ") is not within bounds to get.";
        throw runtime_error(err);
    }
    else if (y >= height)
    {
        string err = "Y coordinate (" + to_string(y) + ") is not within bounds to get.";
        throw runtime_error(err);
    }
    
    return matrix[x][y];
}

void ScoringMatrix::setValue(const unsigned int& x, const unsigned int& y, const int& value)
{
    if (x >= width)
    {
        string err = "X coordinate (" + to_string(x) + ") is not within bounds to set.";
        throw runtime_error(err);
    }
    else if (y >= height)
    {
        string err = "Y coordinate (" + to_string(y) + ") is not within bounds to set.";
        throw runtime_error(err);
    }
    
    matrix[x][y] = value;
}

void ScoringMatrix::printMatrix()
{
    for (int y = 0; y < height; y++)
    {
        cout << " | ";
        for (int x = 0; x < width; x++)
        {
            cout << getValue(x,y) << " | ";
        }
        cout << endl;
    }
}







