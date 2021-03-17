#include <iostream>

using namespace std;

int recursiveFactorial(int n,int index,int factorial);

int main() {
    int n;
    cin >> n;

    int factorial = recursiveFactorial(n,0,1);
    cout << factorial;
    return 0;
}


int recursiveFactorial(int n,int index,int factorial) {
    if(index == n) {
        return factorial;
    }
    //cout << factorial << endl;
    return recursiveFactorial(n,index+1,factorial*(index+1));
}
