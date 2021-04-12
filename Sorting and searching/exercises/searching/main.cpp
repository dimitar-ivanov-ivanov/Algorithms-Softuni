#include <iostream>

using namespace std;

int binaryOperations = 0;


int linearSearch(int arr[],int n,int num) {
    int operations = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == num) {
            cout << "linear operations: " << operations << endl;
            return i;
        }
        operations++;
    }

    return -1;
}

int minVal(int x,int y) {
    return (x<=y)? x : y;
}

int fibonacciSearch(int arr[],int n,int num) {

    int fibFirst = 0;
    int fibSecond = 1;
    int fibThird = fibFirst  + fibSecond;

    while(fibThird < n) {
        fibThird = fibSecond;
        fibSecond = fibThird;
        fibThird = fibFirst + fibSecond;
    }

    int offset = -1;

    while(fibThird > 1) {
        int i = minVal(offset + fibFirst,n-1);

        if(arr[i] < num) {
            fibThird = fibSecond;
            fibSecond = fibFirst;
            fibFirst = fibThird - fibSecond;
            offset = i;
        } else if(arr[i] > num) {
            fibThird = fibFirst;
            fibSecond = fibSecond - fibFirst;
            fibFirst = fibThird - fibSecond;
        } else {
            return i;
        }
    }

    if(fibSecond && arr[offset + 1] == num) {
        return offset + 1;
    }

    return -1;
}

int stepSearch(int arr[],int n,int step,int num) {
    int i,j;
    int operations = 0;

    for(i = 0; i < n; i+=step) {
        if(arr[i] > num) {
            break;
        }
        operations++;
    }

    for(j = i-step; j < i; j++) {
        if(arr[j] == num) {
            cout << "linear operations: " << operations << endl;
            return j;
        }
        operations++;
    }
    return -1;
}

int binarySearch(int arr[],int left,int right,int num) {
    if(right >= left) {
        int mid = left + (right - left)/2;
        binaryOperations++;

        if(arr[mid] == num) {
            return mid;
        }
        if(arr[mid] > num) {
            binarySearch(arr,left,mid-1,num);
        }
        binarySearch(arr,mid+1,right,num);
    }

    return -1;
}

int main() {

    int n = 15;
    int arr[n];

    for(int i = 0; i < n; i++) {
        arr[i] = i+1;
    }

    int linear =  linearSearch(arr,n,14);
    /*only for sorted arrays */
    //int fibonacci = fibonacciSearch(arr,n,5);
    cout << "linear: " << linear << endl;
    //cout << "fibonacci: " << fibonacci << endl;

    int step = stepSearch(arr,n,3,14);
    int binary = binarySearch(arr,0,n,14);
    cout << "step: " << step << endl;
    cout << "binary operations:" << binaryOperations << endl;
    cout << "binary: " << binary << endl;
    return 0;
}
