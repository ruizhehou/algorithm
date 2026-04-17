//
// Created by houruizhe on 2020/10/19.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> s, t;
        for (auto &c : S) {
            if (c == '#') {
                if (!s.empty()) s.pop_back();
            } else s.push_back(c);
        }
        for (auto &c : T) {
            if (c == '#') {
                if (!t.empty()) t.pop_back();
            } else t.push_back(c);
        }
        // cout << s.size() << " " << t.size() << endl;
        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); i++)
            if (s[i] != t[i]) return false;
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.backspaceCompare("ab#c", "ad#c") << endl; // 1
    cout << sol.backspaceCompare("ab##", "c#d#") << endl; // 1
    cout << sol.backspaceCompare("a##c", "#a#c") << endl; // 1
    cout << sol.backspaceCompare("a#c", "b") << endl; // 0
    return 0;
}