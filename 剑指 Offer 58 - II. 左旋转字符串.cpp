//
// Created by Ruizhe Hou on 2020/10/9.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string res = s.substr(n);
        res += s.substr(0, n);
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.reverseLeftWords("abcdefg", 2) << endl; // cdefgab
    cout << sol.reverseLeftWords("lrloseumgh", 6) << endl; // umghlrlose
    return 0;
}