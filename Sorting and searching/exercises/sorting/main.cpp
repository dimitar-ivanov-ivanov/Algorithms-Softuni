#include <iostream>
#include <stdio.h>

using namespace std;

void selectionSort(int arr[],int n) {
    for(int i = 0; i < n; i++) {
        int minVal = arr[i];
        int minIndex = -1;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < minVal) {
                minVal = arr[j];
                minIndex = j;
            }
        }

        if(minIndex != -1) {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

void bubbleSort(int arr[],int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int findPartition(int low,int high,int arr[]) {
    int pivot = arr[high];
    int i = low - 1;

  /*  cout << "low = " << low << endl;
    cout << "high = " << high << endl;
    cout << "pivot = " << pivot << endl;
    cout << "i = " << i << endl;
    cout << "----------------------------------" << endl;
*/
    for(int j = low; j < high; j++) {
        //cout << "j = " << j << endl;
        //cout << "arr[j] = " << arr[j] << endl;

        if(arr[j] < pivot) {
            i++;
            //cout << "i = " << i << endl;
            //cout << "arr[i] = " << arr[i] << endl;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        //cout << "----------------------------------" << endl;
    }

    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quicksort(int low,int high,int arr[]) {
    if(low < high) {
        int pi = findPartition(low,high,arr);
        quicksort(low,pi-1,arr);
        quicksort(pi+1,high,arr);
    }
}

void printArr(int arr[],int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    int n = 6;
    int arr[n];

    for(int i = n; i >= 1; i--) {
        arr[n - i] = i;
    }

    //bubbleSort(arr,n);
    //selectionSort(arr,n);
    quicksort(0,n-1,arr);
    printArr(arr,n);
    return 0;
}
