#include <iostream>

using namespace std;

#define LENGTH 50

void bubbleSort(int arr[LENGTH],int n) {
    int i,j,temp;
    bool swapped;

    for(i = 0; i < n; i++) {

        swapped = false;
        for(j = 0; j < n - i -1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]=temp;
                swapped = true;
            }
        }

        if(swapped == false) {
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[LENGTH];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr,n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
