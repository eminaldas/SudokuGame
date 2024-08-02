#include <iostream>
#include "sudoku.h"
using namespace std;

int main() {
    Sudoku sudoku;
    cout << "Initial Sudoku:\n";
    sudoku.printSudoku();
    sudoku.userInputSolve();
    return 0;
}
