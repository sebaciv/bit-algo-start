#include <iostream>
#include <algorithm>

using namespace std;

void bubbleSort(int *T, const int size) {
    for (int i = size; i > 0; --i) {
        for (int j = 0; j < i-1; ++j) {
            if (T[j] > T[j+1]) {
                swap(T[j], T[j+1]);
            }
        }
    }
}

void printArray(const int *T, const int size) {
    for (int i = 0; i < size; ++i) {
        cout << T[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int *T = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> T[i];
    }
    bubbleSort(T, n);
    printArray(T, n);
    delete[] T;
    return 0;
}
