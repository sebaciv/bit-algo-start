#include <iostream>
#include <vector>

using namespace std;

int binSearch(const vector<int> &vec, const int query) {
    int left = 0;
    int right = vec.size() - 1;
    while (right > left) {
            int center = (left + right) / 2;
            if (vec[center] < query) {
                left = center + 1;
            } else {
                right = center;
            }
        }
    if (vec[left] == query) {
        return left + 1; // +1 because we are indexing from 1, not 0
    } else {
        return -1;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> vec(n);
    for (int i = 0; i < vec.size(); i++) {
        cin >> vec[i];
    }
    for (int i = 0; i < k; i++) {
        int queryNumber;
        cin >> queryNumber;
        cout << binSearch(vec, queryNumber) << " ";
    }
    cout << endl;
    return 0;
}
