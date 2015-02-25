//main.cpp
//main program for Sudoku
//Nicholas Lombardo

#include <iostream>
#include <vector>
#include <fstream>
#include "Puzzle.h"
using namespace std;

int main(){
Puzzle<int> mySudoku("samplePuzzle.txt"); //set up templated Puzzle with int and give parameter for file
Puzzle<char> myWordoku("wordoky.txt"); //set up templated Puzzle with char and give parameter for file
mySudoku.displayBoard(); //display sudoku board
cout << endl << endl; // space between boards
myWordoku.displayBoard(); //display wordoku board
}
