#include <iostream>

using namespace std;


void mergeArr(int arr[], int left, int mid, int right) {
    int leftEnd = mid - left +1;
    int rightEnd = right - mid;

    int leftArr[leftEnd];
    int rightArr[rightEnd];

    for(int i = 0; i < leftEnd; i++) {
        leftArr[i] = arr[left+i];
    }

    for(int i = 0; i < rightEnd; i++) {
        rightArr[i] = arr[mid+i+1];
    }

    int i =0,j =0,k = left;

    while(i < leftEnd && j < rightEnd) {
        if(leftArr[i] <= rightArr[i]) {
            arr[k] = leftArr[i++];
        } else {
            arr[k] = rightArr[j++];
        }
        k++;
    }

    while(i < leftEnd) {
        arr[k++] = leftArr[i++];
    }
    while(j < rightEnd) {
        arr[k++] = rightArr[j++];
    }
}


void mergesort(int arr[],int left,int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        mergeArr(arr,left,mid,right);
    }
}

int main() {
    int a[5] = {7,5,3,2,1};
    mergesort(a,0,4);
    for(int i = 0; i < 5; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
