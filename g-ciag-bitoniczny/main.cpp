#include <iostream>
#include <vector>

using namespace std;

int binSearchMax(const vector<int> &array) {
    int left = 0;
    int right = array.size() - 1;
    while (right - left > 0) {
        int middle = (right + left) / 2;
        if (array[middle] > array[middle+1]) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return array[left];
}

int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < array.size(); i++) {
        cin >> array[i];
    }
    cout << binSearchMax(array) << endl;
}
