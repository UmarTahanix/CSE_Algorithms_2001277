#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;

int ways = 0, steps = 0;

void printSquare(const vector<int>& square){
	cout << ++ways << ") " << endl;
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			cout << square[i*SIZE + j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool isMagicSquare(const vector<int>& square){
	int value = square[0] + square[1] + square[2]; //Summation of values of first row (Default)

    for(int i = 0; i < SIZE; i++){ //Rows & Columns
        int sum_row = 0, sum_col = 0;
		for(int j = 0; j < SIZE; j++){ //Calculate the sum of values of current row and column
            sum_row += square[i*SIZE + j];
            sum_col += square[j*SIZE + i];
        }
        if(sum_row != value || sum_col != value) //Checks whether equal to the default value or not
            return false;
    }

	int sum_diagonal = 0, sum_diagonal_anti = 0; //Summation of each row/column/diagonal          Square index: 0 1 2
    for(int i = 0; i < SIZE; i++){ //Diagonals																	3 4 5	
        sum_diagonal += square[i*(SIZE+1)]; //0 -> 4 -> 8														6 7 8
        sum_diagonal_anti += square[2*(i+1)]; // 2 -> 4 -> 6
    }
    if(sum_diagonal != value || sum_diagonal_anti != value)
        return false;

    return true;
}

void permutation(vector<int>& numbers, vector<int>& square, vector<bool>& used, int index){
	steps++;

	if(index == SIZE*SIZE){ //After filling the square
		if(isMagicSquare(square)){
			printSquare(square);
		}	
		return;
	}

	for(int i = 0; i < numbers.size(); i++){
		if(!used[i]){//The number isn't previously used
			square[index] = numbers[i]; //Storing the number in the square
			used[i] = true; //Mark used so not to use it in the square again
			permutation(numbers, square, used, index + 1); //Proceed
			used[i] = false; //After filling the square, mark as unused to use it in the next square
		}
	}
}

int main(){
	vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> square(SIZE*SIZE); //Square
	vector<bool> used(numbers.size(), false); //Whether the number is used on not 
	
	permutation(numbers, square, used, 0);

	cout << "Number of ways to fill the table = " << ways << endl;

	cout << "\nNumber of steps = " << steps << endl; //Output the number of steps done in permutation function
	return 0;
}