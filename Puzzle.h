//Puzzle.h
//Nicholas Lombardo
//Puzzle class for Sudoku game
//stores puzzle and outputs puzzle

#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>

using namespace std;

friend ostream& operator<<(ostream& output, Puzzle& myPuzzle);

class Puzzle{
	public:
		Puzzle(); //constructor
		
	private:
		vector <vector <int>> Board;
}
#endif
