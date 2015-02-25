//main.cpp
//main program for Sudoku
//Nicholas Lombardo

#include <iostream>
#include <vector>
#include <fstream>
#include "Puzzle.h"
using namespace std;

int main(){
Puzzle<int> mySudoku("samplePuzzle.txt");
Puzzle<char> myWordoku("wordoky.txt");
mySudoku.displayBoard();
cout << endl << endl; // space between boards
myWordoku.displayBoard();
}
