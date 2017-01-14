#include <string>
#include <iostream>

using namespace std;

string vowels = "aeouyi";

bool is_vowel(const char c) {
    return vowels.find(c) != string::npos;
}

bool check(const int num_of_vowels, const int ascii_sum, string s_out, string s_in, const int position) {
    if (num_of_vowels == 0 and ascii_sum == 0) {
        return true;
    }
    if (num_of_vowels < 0 or ascii_sum < 0 or position >= s_in.length()) {
        return false;
    }
    int new_num_of_vowels = is_vowel(s_in[position]) ? num_of_vowels - 1 : num_of_vowels;
    return check(new_num_of_vowels, ascii_sum - s_in[position], s_out + s_in[position], s_in, position + 1)
           or
           check(num_of_vowels, ascii_sum, s_out, s_in, position + 1);
}

bool compare(const string s1, const string s2) {
    int num_of_vowels = 0;
    int ascii_sum = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (is_vowel(s1[i])) {
            num_of_vowels++;
        }
        ascii_sum += s1[i];
    }
    return check(num_of_vowels, ascii_sum, "", s2, 0);
}

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    if (compare(s1, s2)) {
        cout << "TAK";
    } else {
        cout << "NIE";
    }
    return 0;
}
