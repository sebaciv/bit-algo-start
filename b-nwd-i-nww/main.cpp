#include <iostream>
#include <algorithm>

using namespace std;

long long NWD(long long a, long long b) {
    if (a > b) {
        swap(a, b);
    }
    if (a == 0LL) {
        return b;
    }
    return NWD(b % a, a);
}

int main() {
    int z;
    cin >> z;
    for (int i = 0; i < z; ++i) {
        long long a, b;
        cin >> a >> b;
        long long nwd = NWD(a, b);
        long long nww = (a * b) / nwd;
        cout << nwd << " " << nww << endl;
    }
    return 0;
}
