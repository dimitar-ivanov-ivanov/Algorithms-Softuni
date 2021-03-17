#include <iostream>
#include <vector>

using namespace std;

int recursiveSum(std::vector<int> v,int n,int index,int sum);

int main() {
    int n;
    std::vector<int> v;
    cin >> n;

    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int sum = recursiveSum(v,n,0,0);
    cout << sum;
    return 0;
}

int recursiveSum(std::vector<int> v,int n,int index,int sum) {
    if(index == n) {
        return sum;

    }
    return recursiveSum(v,n,index+1,sum + v[index]);
}
