//
// Created by Ruizhe Hou on 2020/10/2.
//
#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> s;
        for (char c : J) {
            s.insert(c);
        }
        int res = 0;
        for (char c: S) {
            if (s.count(c)) res++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.numJewelsInStones("aA", "aAAbbbb") << endl; // 3
    cout << sol.numJewelsInStones("z", "ZZ") << endl; // 0
    return 0;
}