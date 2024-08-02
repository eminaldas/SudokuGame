#include <ctime>
#include <iostream>
#include <sstream>
#include "sudoku.h"

using namespace std;

Sudoku::Sudoku() {
    srand(time(0));
    int row = 0, column = 0, value = 0;

    for (int ix = 0; ix < 4; ix++) {
        int boxFill = randomNumber(6, 1);

        for (int ii = 1; ii <= boxFill; ii++) {
        label1:
            row = randomNumber(2, 0);
            column = randomNumber(2, 0);
        label:
            value = randomNumber(9, 1);

            if (!boxCheck(ix, column, row, value)) {
                goto label1;
            }
            for (int i = 0; i < 3; i++) {
                for (int ii = 0; ii < 3; ii++) {
                    if (this->sudokuMatris[ix][i][ii] == value) {
                        goto label;
                    }
                }
            }

            if (this->sudokuMatris[ix][column][row] < 1) {
                this->sudokuMatris[ix][column][row] = value;
            }
            else {
                ii--;
            }
        }
    }
}

bool Sudoku::boxCheck(int box, int row, int column, int value) {
    if (box == 0) {
        for (int i = 0; i < 3; i++) {
            if (sudokuMatris[1][row][i] == value) {
                return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (sudokuMatris[2][i][column] == value) {
                return false;
            }
        }
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                if (sudokuMatris[box][a][b] == value) {
                    return false;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            if (i == column) {
                continue;
            }
            else if (sudokuMatris[box][row][i] == value) {
                return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (i == row) {
                continue;
            }
            else if (sudokuMatris[box][i][column] == value) {
                return false;
            }
        }
    }

    if (box == 1) {
        for (int i = 0; i < 3; i++) {
            if (sudokuMatris[0][row][i] == value) {
                return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (sudokuMatris[3][i][column] == value) {
                return false;
            }
        }
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                if (sudokuMatris[box][a][b] == value) {
                    return false;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            if (i == column) {
                continue;
            }
            else if (sudokuMatris[box][row][i] == value) {
                return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (i == row) {
                continue;
            }
            else if (sudokuMatris[box][i][column] == value) {
                return false;
            }
        }
    }

    if (box == 2) {
        for (int i = 0; i < 3; i++) {
            if (sudokuMatris[3][row][i] == value) {
                return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (sudokuMatris[0][i][column] == value) {
                return false;
            }
        }
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                if (sudokuMatris[box][a][b] == value) {
                    return false;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            if (i == column) {
                continue;
            }
            else if (sudokuMatris[box][row][i] == value) {
                return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (i == row) {
                continue;
            }
            else if (sudokuMatris[box][i][column] == value) {
                return false;
            }
        }
    }

    if (box == 3) {
        for (int i = 0; i < 3; i++) {
            if (sudokuMatris[2][row][i] == value) {
                return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (sudokuMatris[1][i][column] == value) {
                return false;
            }
        }
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                if (sudokuMatris[box][a][b] == value) {
                    return false;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            if (i == column) {
                continue;
            }
            else if (sudokuMatris[box][row][i] == value) {
                return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (i == row) {
                continue;
            }
            else if (sudokuMatris[box][i][column] == value) {
                return false;
            }
        }
    }
    return true;
}

int Sudoku::randomNumber(int max, int min) {
    int value = 0;

    try {
        value = rand() % (max - min + 1) + min;
    }
    catch (exception& e) {
        cout << "hata";
    }

    return value;
}

void Sudoku::printSudoku() {
    for (int ix = 0; ix < 4; ix += 2) {
        cout << endl << endl;
        for (int i = 0; i < 3; i++) {
            cout << endl;
            cout << "| ";
            for (int ii = 0; ii < 3; ii++) {
                if (this->sudokuMatris[ix][i][ii] < 1) {
                    cout << " - ";
                }
                else {
                    cout << " " << this->sudokuMatris[ix][i][ii] << " ";
                }
            }
            cout << " |";
            cout << "| ";
            for (int ii = 0; ii < 3; ii++) {
                if (this->sudokuMatris[ix + 1][i][ii] < 1) {
                    cout << " - ";
                }
                else {
                    cout << " " << this->sudokuMatris[ix + 1][i][ii] << " ";
                }
            }
            cout << " |";
        }
    }
}

bool Sudoku::solve() {
    int row = -1;
    int col = -1;
    int box = -1;
    bool isEmpty = true;

    for (int b = 0; b < 4; b++) {
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (sudokuMatris[b][r][c] == 0) {
                    row = r;
                    col = c;
                    box = b;
                    isEmpty = false;
                    b = 4;
                    break;
                }
            }
            if (!isEmpty) break;
        }
        if (!isEmpty) break;
    }

    if (isEmpty) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (boxCheck(box, row, col, num)) {
            sudokuMatris[box][row][col] = num;
            if (solve()) {
                return true;
            }
            else {
                sudokuMatris[box][row][col] = 0;
            }
        }
    }

    return false;
}

void Sudoku::userInputSolve() {
    int box, row, column, value;
    string input;
    while (true) {
        printSudoku();
        cout << "\nEnter box, row, column, and value (e.g., 0 0 0 5), 'remove' to delete a value, or 'solve' to auto-solve: ";
        getline(cin, input);
        if (input == "solve") {
            if (solve()) {
                cout << "\nSolved Sudoku:\n";
                printSudoku();
            }
            else {
                cout << "\nNo solution exists!\n";
            }
            break;
        }
        else if (input.find("remove") == 0) {
            istringstream iss(input.substr(7)); // Remove the command part "remove "
            if (iss >> box >> row >> column) {
                if (box >= 0 && box < 4 && row >= 0 && row < 3 && column >= 0 && column < 3) {
                    sudokuMatris[box][row][column] = 0;
                    cout << "\nValue removed successfully.\n";
                }
                else {
                    cout << "\nInvalid position. Please try again.\n";
                }
            }
            else {
                cout << "\nInvalid format. Please use 'remove <box> <row> <column>'.\n";
            }
        }
        else {
            istringstream iss(input);
            if (iss >> box >> row >> column >> value) {
                if (isValidInput(box, row, column, value)) {
                    sudokuMatris[box][row][column] = value;
                }
                else {
                    cout << "\nInvalid input. Please try again.\n";
                }
            }
            else {
                cout << "\nInvalid format. Please try again.\n";
            }
        }
    }
}

bool Sudoku::isValidInput(int box, int row, int column, int value) {
    if (box < 0 || box > 3 || row < 0 || row > 2 || column < 0 || column > 2 || value < 1 || value > 9) {
        return false;
    }
    if (!boxCheck(box, row, column, value)) {
        return false;
    }
    return sudokuMatris[box][row][column] == 0;
}
