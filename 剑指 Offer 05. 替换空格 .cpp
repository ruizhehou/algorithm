//
// Created by Ruizhe Hou on 2020/10/8.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0, len = s.size();
        for (char c : s) {
            if (c == ' ') count++;
        }
        s.resize(len + 2 * count);
        for (int i = len - 1, j = s.size() - 1; i < j; i--, j--) {
            if (s[i] == ' ') {
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j -= 2;
            } else {
                s[j] = s[i];
            }
        }
        return s;
    }
};

int main() {
    Solution sol;
    cout << sol.replaceSpace("We are happy.") << endl; // We%20are%20happy.
    return 0;
}
