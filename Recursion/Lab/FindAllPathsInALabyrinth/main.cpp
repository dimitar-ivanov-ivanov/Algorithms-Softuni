#include <iostream>
#include <vector>

using namespace std;
#define ROWS 20
#define COLS 20
#define LENGTH 400

void findExit(int arr[ROWS][COLS],int row,int col,int n,int m,int output[LENGTH],int index) {

    //found exit
    if(arr[row][col] == 2) {
        for(int i = 0; i < index; i++) {
            cout << output[i];
        }
        cout << "\n";
        return;
    }

    //findExit(arr,row+1,col);
    arr[row][col] = -1;

    if(row + 1 < n && arr[row+1][col] != -1) {
        output[index] = 1;
        findExit(arr,row+1,col,n,m,output,index+1);
    }
    if(row - 1 >= 0 && arr[row-1][col] != -1) {
        output[index] = 2;
        findExit(arr,row-1,col,n,m,output,index+1);
    }
    if(col + 1 < m && arr[row][col+1] != -1) {
        output[index] = 3;
        findExit(arr,row,col+1,n,m,output,index+1);
    }
    if(col - 1 >=0 && arr[row][col-1] != -1) {
        output[index] = 4;
        findExit(arr,row,col-1,n,m,output,index+1);
    }

    arr[row][col] = 0;
}

int main() {
    int n,m;
    cin >> n >> m;
    int arr[ROWS][COLS];
    int output[LENGTH];

    for(int i = 0; i < LENGTH; i++) {
        output[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            int val;
            cin >> c;

            if(c == '*') {
                val = -1;
            }
            if(c == '-') {
                val = 0;
            }
            if(c == 'e') {
                val = 2;
            }

            arr[i][j] = val;
        }
    }

    findExit(arr,0,0,n,m,output,0);
    return 0;
}
