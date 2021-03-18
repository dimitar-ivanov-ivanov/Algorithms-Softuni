#include <iostream>
#include <vector>

using namespace std;

void printArrayBackwards(vector<int> v,int n,int index) {
    if(index == n) {
        return;
    }

    printArrayBackwards(v,n,index+1);
    cout << v[index] << " ";
}

int main() {
    int n;
    cin>>n;
    vector<int> v;
    v.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    printArrayBackwards(v,n,0);
    return 0;
}
