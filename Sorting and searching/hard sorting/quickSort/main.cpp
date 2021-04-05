#include <iostream>

using namespace std;

static void swapNums(int arr[],int i,int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j]= temp;
}

static int findPartition(int low,int high,int arr[]) {
    int pivot = arr[high];
    int i = low -1;

    for(int j = low; j<=high-1; j++) {
        if(arr[j] < pivot) {
            i++;
            swapNums(arr,i,j);
        }
    }
    swapNums(arr,i+1,high);
    return i + 1;
}

static void quicksort(int low,int high,int arr[]) {
    if(low < high) {
        int pi = findPartition(low,high,arr);
        quicksort(low,pi-1,arr);
        quicksort(pi+1,high,arr);
    }
}

int main() {
    int arr[6] = {6,5,4,3,2,1};
    quicksort(0,5,arr);
    for(int i = 0; i < 6; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
