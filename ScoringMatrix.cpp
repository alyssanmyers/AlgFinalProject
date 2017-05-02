/*************************************************************/
// Alyssa Myers & Luciano Mogorovic
// 3460:435 Algorithms
// Project 4 — DNA Sequence Alignment
// May 3, 2017
//
// Comparing two sequences using dynamic programming algorithm.
/*************************************************************/

#include <string>
#include <vector>

using namespace std;

class ScoringMatrix
{
private:
    unsigned int width, height;
    string sequence1, sequence2;
    vector<vector<int>> matrix;
    
public:
    
    // constructs a new matrix
    ScoringMatrix();
    ScoringMatrix(string, string);
    
    // sets the first row and column
    void generateFirstRC(int);
    
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
    
    width = sequence1.length();
    height = sequence2.length();
    
    matrix.resize(width);
    for (auto& entry : matrix)
    {
        entry.resize(height);
    }
}

void ScoringMatrix::generateFirstRC(int gap)
{
    // set up the first row with gap value
    for (int i = 0; i < width; i++)
    {
        matrix[i][0] = i * gap;
    }
    
    // set up the first column with gap value
    for (int j = 0; j < height; j++)
    {
        matrix[0][j] = j * gap;
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
    for (int j = 0; j < height; j++)
    {
        cout << " | ";
        for (int i = 0; i < width; i++)
        {
            if(getValue(i,j) >= 0)
                cout << getValue(i,j) << "  | ";
            else
                cout << getValue(i,j) << " | "; 
        }
        cout << endl;
    }
}







