//Puzzle.h
//Nicholas Lombardo
//Puzzle class for Sudoku game
//stores puzzle and outputs puzzle

#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class Puzzle{
	
	friend ostream& operator<<(ostream&, Puzzle&);

	public:
		Puzzle(); //constructor
		
	private:
		vector<vector <int> > Board;
};

//Function Implementations
Puzzle::Puzzle(){ //constructor
	int value, i = 0, j = 0;
	ifstream infile;
	vector<int> rowVec;
	infile.open("samplePuzzle.txt");
	for (int i = 0; i < 9; i++){
		for( int j = 0; j < 9; j++) {
			infile >> value;
			rowVec.push_back(value);
		}
		Board.push_back(rowVec);
		rowVec.clear();
	}
}

ostream& operator<<(ostream& output, Puzzle& myPuzzle){
	cout << "    ";
	for (int k = 1; k < 10; k++){
		cout << k << " ";
	}
	cout << endl << "    - - - - - - - - -" <<  endl;
	for (int i = 0; i < 9; i++){
		cout << i + 1 << " | ";
		for( int j = 0; j < 9; j++) {
			output << myPuzzle.Board[i][j] << " ";
		}
			cout << endl;
	}
	return(output);
}
#endif
