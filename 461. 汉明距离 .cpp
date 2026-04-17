//
// Created by Ruizhe Hou on 2020/10/7.
//
#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        return bitset<32>(x ^ y).count();
    }
};

int main() {
    Solution sol;
    cout << sol.hammingDistance(1, 4) << endl; // 2
    cout << sol.hammingDistance(3, 1) << endl; // 1
    return 0;
}
