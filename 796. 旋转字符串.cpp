//
// Created by Ruizhe Hou on 2020/9/17.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};

int main() {
    Solution sol;
    cout << sol.rotateString("abcde", "cdeab") << endl; // 1
    cout << sol.rotateString("abcde", "abced") << endl; // 0
    return 0;
}