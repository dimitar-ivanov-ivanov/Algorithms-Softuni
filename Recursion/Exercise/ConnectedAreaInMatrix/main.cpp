#include <iostream>
#include <stdio.h>

using namespace std;

#define ROWS 50
#define COLS 50

int areaCount = 0;
int areaSize = 0;

void findPath(int arr[ROWS][COLS],int n,int m,int row,int col) {

    arr[row][col] = -1;
    areaSize++;

    if(row + 1 < n && arr[row+1][col] != -1) {
        findPath(arr,n,m,row+1,col);
    }
    if(row - 1 >= 0 && arr[row-1][col] != -1) {
        findPath(arr,n,m,row-1,col);
    }
    if(col + 1 < m && arr[row][col + 1] != -1) {
        findPath(arr,n,m,row,col+1);
    }
    if(col - 1 >=0 && arr[row][col-1] != -1) {
        findPath(arr,n,m,row,col-1);
    }
}

void traverseMatrix(int arr[ROWS][COLS],int n,int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                areaSize = 0;
                findPath(arr,n,m,i,j);
                if(areaSize > 1) {
                    areaCount++;
                }

                printf("Area #%d at (%d, %d), size: %d\n",
                       areaCount,i,j,areaSize);
            }
        }
    }
}

int main() {
    int n,m,arr[ROWS][COLS];
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;

            if(c == '-') {
                arr[i][j] = 0;
            } else {
                arr[i][j] = -1;
            }
        }
    }

    traverseMatrix(arr,n,m);
    return 0;
}
