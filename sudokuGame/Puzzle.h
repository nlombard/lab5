//Puzzle.h
//Nicholas Lombardo
//Puzzle class for Sudoku game
//stores puzzle and couts puzzle

#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
using namespace std;

template<typename T>
class Puzzle{	
	public:
		Puzzle(string); //constructor
		void displayBoard(); //display function for printing board
		int checkValid(int, int, int); //checks whether placing certain number in grid is valid
		int checkGrid(int,int,int); //checks if mini grid is valid for placement of number
		void play(); //main game to play calls other functions to simulate soduku
		int didWin(); //checks if winner
	private:
		vector<vector < T > > Board; //storage for Board, a 2D vector
		vector<vector < T > > OriginalBoard; //storage for OriginalBoard, a 2D vector of original values
};

//Function Implementations
template <typename T>
Puzzle<T>::Puzzle(string dataFile){ //constructor
	int i = 0, j = 0;
	T value; //value of data type T from template
	ifstream infile; //creates stream variable
	vector<T> rowVec; //vector for storage of row, then put into vector of vector
	infile.open(dataFile.c_str()); //open datafile for read in
	for (int i = 0; i < 9; i++){
		for( int j = 0; j < 9; j++) {
			infile >> value; //read in value
			rowVec.push_back(value); //put into vector
		}
		Board.push_back(rowVec); //put vector into board
		rowVec.clear(); //clear storage vector for next row
	}
	OriginalBoard = Board; //set OrignalBoard equal to the Board read in with no user changes
}
template <typename T>
void Puzzle<T>::displayBoard(){	//display function
	cout << "    "; //formating
	for (int k = 1; k < 10; k++){
		cout << k << " "; //output numbers for grid
	}
	cout << endl << "    - - - - - - - - -" <<  endl; //formating
	for (int i = 0; i < 9; i++){
		cout << i + 1 << " | "; //output for grid
		for( int j = 0; j < 9; j++) {
			cout << Board[i][j] << " "; //display board number and space
		}
			cout << endl;
	}
}
template <typename T>
int Puzzle<T>::checkValid(int x, int y, int z){
	if((x < 0)||(x > 9)||(y < 0)||(y > 9)||(z>9)||(z<0)){
		cout << "Error: row or col and/or num out of range!" << endl;
		return 0; //leave if numbers are out of bounds		
	}
	int countRow[10]; //initalize count array
	int countCol[10]; //initalize count array
	for(int i=0;i<10;i++){
		countRow[i] = 0; //set values to 0
		countCol[i] = 0; //set values to 0
	}
	if(OriginalBoard[x][y] != 0){
		cout << "Error: cannot change original values." << endl;
		return 0; //cannot place invalid
	}
	for(int i=0;i<9;i++){
		countRow[Board[x][i]]++; //increment count	
	}
	if(countRow[z]>=1){
		if(z == 0){
			return 1; // allow reset to 0 even if there are zeros in the row
		}
		cout << "Error: number already exists in row!" << endl;
		return 0; //cannot place invalid because more than one in row
	}
	for(int i=0;i<9;i++){
		countCol[Board[i][y]]++; //increment count
	}
	if(countCol[z]>=1){
		if(z == 0){
			return 1; //allow reset to 0 even if there are zeros in the col
		} 
		cout << "Error: number already exists in col!" << endl;
		return 0; //cannot place invalid because more than one in row
	}
	if(checkGrid(x,y,z) == 0){
		cout << "Error: number already exists in Grid" << endl;
		return 0; //return if number is in Grid
	}
	return 1; // if no errors then it can be placed
}
template <typename T>
int Puzzle<T>::checkGrid(int x, int y, int z){
	int i = (x/3)*3; //start position using integer division to find correct Grid
	int j = (y/3)*3;
	int count[10];
	for(int l = 0; l < 10; l++){
		count[l] = 0; //initalize count values to zero
	}
	for(int k = 0; k < 3; k++){
		for(int k = 0; k < 3; k++){
			count[Board[i][j]]++;
			j++; //increment i and j to next spots
		}
		i++; // increment row
		j = (y/3)*3; //reset column
	}
	if(count[z]>=1){
		if(z == 0){
			return 1; //allow for 0 to be placed in Grid
		}
		return 0;
	}
	return 1; // if no errors then return 1
}
template <typename T>
void Puzzle<T>::play(){
	int x, y, z = 0;
	while(!didWin()){ //quit when game over
		displayBoard(); 
		cout << "Where and what would you like to play?" << endl << "(Enter row col num): ";
		cin >> x >> y >> z; //take in row and col
		if(z == -1){
			return; //end game if z = -1
		}
		x--; y--; //take them into board terms users sees 1-9 computer sees 0-8
		system("clear");
		if(checkValid(x,y,z)){ //if it can be placed, place
			Board[x][y] = z; //set board value
		}
	}
	if(didWin()){ //if no zeros left then board is solved
		displayBoard(); 
		cout << "Conrats! You Won!" << endl;
	}
}
template <typename T>
int Puzzle<T>::didWin(){ //did win function to check if there are no zeros on the board
	for(int i=0;i<9;i++){ //if every placement is checked then when there are no zeros left the board is solved
		for(int j=0;j<9;j++){
			if(Board[i][j] == 0)
				return 0; //still an empty spot
		}
	}
	return 1; //return 1 if after the whole board is checked there is no zeros (empty spots)
}
#endif
