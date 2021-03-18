#include <iostream>

using namespace std;

#define ROWS 8
#define COLS 8

void generateEightQueensPuzzle(int matrix[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; i < COLS; i++) {
            if(matrix[i][j] == 0) {
                matrix[i][j] = 1;

                //mark horizontal
                for(int k = 0; k < COLS; k++) {
                    matrix[i][k] = 1;
                }

                //mark vertical
                for(int k = 0; k < ROWS; k++) {
                    matrix[k][j] =1;
                }

                //mark diagonals
                for(int k = 0; k < ROWS; k++) {
                    if(i + k < ROWS  && j + k < COLS) {
                        matrix[i+k][j+k] = 1;
                    }
                    if(i + k < ROWS  && j - k >= 0) {
                        matrix[i+k][j-k] = 1;
                    }
                    if(i - k >=0 && j + k < COLS) {
                        matrix[i-k][j+k] = 1;
                    }
                    if(i - k >=0 && j - k >=0) {
                        matrix[i-k][j-k] = 1;
                    }
                }
                generateEightQueensPuzzle(matrix);
            }
        }
    }

    //no more free spaces
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            cout << matrix[i][j
            ];
        }
        cout << "\n";
    }
    //end program
}

int main() {
    int i,j;
    int matrix[ROWS][COLS];

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            matrix[i][j] = 0;
        }
    }


    cout << "Hello world!" << endl;
    return 0;
}
