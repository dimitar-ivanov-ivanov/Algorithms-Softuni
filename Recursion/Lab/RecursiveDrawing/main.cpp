#include <iostream>

using namespace std;

void draw(int n,char first,char second) {
    if(n == 0) {
        return;
    }

    for(int i = 0; i < n; i++) {
        cout << first;
    }

    cout << "\n";
    draw(n-1,first,second);

    for(int i = 0; i < n; i++) {
        cout << second;
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    draw(n,'*','#');
    return 0;
}
