#include <iostream>
#include <vector>

using namespace std;

void generateCombinations(int n,int k,vector<int> v,int index,int num) {
    if(index == k) {
        for(int i = 0; i < k; i++) {
            cout << v[i];
        }
        cout << "\n";
        return;
    }

    for(int i = num; i <= n; i++) {
        v[index] = i;
        generateCombinations(n,k,v,index+1,i+1);
    }
}

int main() {
    int n,k;
    cin>>n >> k;
    vector<int> v;
    v.resize(k);
    generateCombinations(n,k,v,0,1);
    return 0;
}
