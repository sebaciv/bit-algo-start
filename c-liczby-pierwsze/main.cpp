#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n == 1) {
        return false;
    }
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int z;
    cin >> z;
    for (int i = 0; i < z; ++i) {
        int n;
        cin >> n;
        if (isPrime(n)) {
            cout << "TAK" << endl;
        } else {
            cout << "NIE" << endl;
        }
    }
    return 0;
}
