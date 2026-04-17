//
// Created by Ruizhe Hou on 2020/10/8.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        int cur, n = s.length();
        string ans;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '#') {
                cur = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                i -= 2;
            } else {
                cur = s[i] - '0';
            }
            ans = char(cur - 1 + 'a') + ans;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.freqAlphabets("10#11#12") << endl; // jkab
    cout << sol.freqAlphabets("1326#") << endl; // acz
    return 0;
}
