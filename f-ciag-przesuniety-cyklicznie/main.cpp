#include <iostream>
#include <vector>

using namespace std;

// finds index where sorted array was cut
int findShift(const vector<int> &array) {
    int shift = 0;
    if (array[array.size()-1] <= array[0]) {
        int left = 0;
        int right = array.size() - 1;
        while (right > left) {
            int center = (left + right) / 2;
            if (array[center] > array[left]) {
                left = center + 1;
            } else {
                right = center;
            }
        }
        if (array[0] > array[1]) {
            shift = 1;
        } else {
            shift = left;
        }
    }
    return shift;
}

int binSearch(const vector<int> &array, const int shift, const int query) {
    int left = shift;
    int right = array.size() + shift - 1;
    while (right > left) {
        int center = (left + right) / 2;
        if (array[center % array.size()] < query) {
            left = center + 1;
        } else {
            right = center;
        }
    }
    if (array[left % array.size()] == query) {
        return left % array.size() + 1; // +1 because we are indexing from 1, not 0
    } else {
        return -1;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> array(n);
    for (int i = 0; i < array.size(); i++) {
        cin >> array[i];
    }
    int shift = findShift(array); // smallest number in array is at array[shift]
    for (int i = 0; i < k; i++) {
        int query;
        cin >> query;
        cout << binSearch(array, shift, query) << " ";
    }
    cout << endl;
    return 0;
}
