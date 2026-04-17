//
// Created by Ruizhe Hou on 2020/10/2.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int> &indices) {
        int n = s.length();
        string res(n, 0);
        for (int i = 0; i < n; i++) {
            res[indices[i]] = s[i];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> indices1 = {4, 5, 6, 7, 0, 2, 1, 3};
    cout << sol.restoreString("codeleet", indices1) << endl; // leetcode
    vector<int> indices2 = {0, 1, 2, 3};
    cout << sol.restoreString("abc", indices2) << endl; // abc (only 3 chars used)
    return 0;
}