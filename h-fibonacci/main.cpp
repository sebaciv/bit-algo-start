#include <iostream>

using namespace std;

const int MAX_N = 90;
long long int fib[MAX_N+1];

long long int fibonacci_mem(int n) {
    if (n == 0 or n == 1) {
        return n;
    }
    if (fib[n-2] == -1) {
        fib[n-2] = fibonacci_mem(n-2);
    }
    if (fib[n-1] == -1) {
        fib[n-1] = fibonacci_mem(n-1);
    }
    return fib[n-2] + fib[n-1];
}


int main() {
    for (int i = 0; i < MAX_N+1; i++) {
        fib[i] = -1;
    }
    int n;
    cin >> n;
    cout << fibonacci_mem(n) << endl;
    return 0;
}
