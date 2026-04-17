//
// Created by Ruizhe Hou on 2020/10/10.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int h[26];

    inline bool haveChar() {
        for (int i: h) {
            if (i) {
                return true;
            }
        }
        return false;
    }

    string sortString(string s) {
        for (char &c : s) {
            ++h[c - 'a'];
        }
        string res;

        auto appendChar = [&](int p) {
            if (h[p]) {
                --h[p];
                res.push_back(p + 'a');
            }
        };

        while (true) {
            if (!haveChar()) break;
            for (int i = 0; i < 26; i++) appendChar(i);
            for (int i = 25; i >= 0; i--) appendChar(i);
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.sortString("aaaabbbbcccc") << endl; // abccbaabccba
    cout << sol.sortString("rat") << endl; // art
    return 0;
}
