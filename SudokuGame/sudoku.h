#pragma once
#include <iostream>

class Sudoku {
public:
    Sudoku();

    bool boxCheck(int box, int row, int column, int value);
    int randomNumber(int max = 0, int min = 0);
    void printSudoku();
    bool solve();
    void userInputSolve();

private:
    int sudokuMatris[4][3][3] = {};
    bool isValidInput(int box, int row, int column, int value);
};
