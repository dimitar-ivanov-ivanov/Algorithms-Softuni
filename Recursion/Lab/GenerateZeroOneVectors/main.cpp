#include <iostream>
#include <vector>

using namespace std;

void generateVectors(vector<int> v,int n,int index) {
    if(index == n) {
        for(int i = 0; i < n; i++) {
            cout << v[i];
        }
        cout << "\n";
        return;
    }

    v[index] = 0;
    generateVectors(v,n,index+1);

    v[index] = 1;
    generateVectors(v,n,index+1);

}

int main() {
    int n;
    cin>>n;
    vector<int> v;
    v.resize(n);
    generateVectors(v,n,0);
    return 0;
}
