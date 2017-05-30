3460:435 Algorithms Final Project — DNA Sequence Alignment 05/05/2017
Alyssa Myers & Luciano Mogorovic

General Description
———————————————————
Comparing two DNA sequences using dynamic programming sequence alignment algorithm.

Execution
—————————
1) Go to the project directory via command line.
2) SeqAlign is to be ran using C++11 compiler.
3) The first command line argument is the first DNA sequence of chars (a/t/c/g).
4) The second command line argument is the second DNA sequence of chars (a/t/c/g).

Sequence Alignment
——————————————————
o Input of two sequences and create a n * m sized matrix.
  n = length of sequence 1     m = length of sequence 2
o First row = n * gap     First column = m * gap
o For each cell, choose the max, and record in the matrix
  - SCORE { Diagonal Cell + SCORE { i_m, i_n }
          { Left Cell + SCORE { i_m, _ )
          { Top Cell + SCORE { _, j_m }
o Trace back 

Files
—————
o SeqAlign - main file.
o ScoringMatrix - a 2D vector array that is easily manipulated.
o SeqAligner - functions that perform the sequence alignment algorithm.

Usage
—————
1) ./SeqAlign sequence1 sequence2
