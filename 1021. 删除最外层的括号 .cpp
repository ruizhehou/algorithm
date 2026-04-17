//
// Created by Ruizhe Hou on 2020/10/7.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int cnt = 0;
        for (char c : S) {
            if (c == '(') {
                if (cnt++) res.push_back(c);

            } else {
                if (--cnt) res.push_back(c);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.removeOuterParentheses("(()())(())") << endl; // ()()()
    cout << sol.removeOuterParentheses("(()())(())(()(()))") << endl; // ()()()()(())
    return 0;
}
