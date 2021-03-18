#include <iostream>
#include <vector>

using namespace std;

void generatePermutations(vector<int> v,int n,int index) {

    if(index == n) {
        for(int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }


    for(int i = 1; i <= n; i++) {
        v[index] = i;
        generatePermutations(v,n,index+1);
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v;
    v.resize(n);

    generatePermutations(v,n,0);
    return 0;
}
