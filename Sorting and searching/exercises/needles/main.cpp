#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int arr[],int n,int left,int right,int needle) {
    int mid = left + (right - left)/2;
    if(arr[right] < needle) {
        return right;
    }
    if(arr[mid] < needle) {
        return mid;
    }

    return -1;
}

int main() {
    int arrLen,needleLen,num,needle,lastNum;
    cin >> arrLen >> needleLen;

    vector<int> v;
    vector<int> zeroIndices;
    lastNum = -1;
    for(int i = 0; i < arrLen; i++) {
        cin >> num;
        v.push_back(num);
        if(num == 0 && lastNum != 0) {
            zeroIndices.push_back(i);
        }
        if(num != 0 && lastNum == 0) {
            zeroIndices.push_back(i);
        }
        lastNum = num;
    }

    for(int i = 0; i < needleLen; i++) {
        cin >> needle;
        int zerosIndex = 1;
        for(int j = 0; j < arrLen; j++) {
            if(v[j] == 0) {
                j= zeroIndices[zerosIndex] - 1;
                zerosIndex++;
            }
        }
    }


    return 0;
}
