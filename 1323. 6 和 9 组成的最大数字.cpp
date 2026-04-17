//
// Created by Ruizhe Hou on 2020/10/9.
//
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximum69Number(int num) {
        int res = num, i = -1, j = 0;
        while (num) {
            if (num % 10 == 6) {
                i = j;
            }
            num /= 10;
            j++;
        }
        if (i == -1) return res;
        return res + (int) (3 * pow(10, i));
    }
};

int main() {
    Solution sol;
    cout << sol.maximum69Number(9669) << endl; // 9969
    cout << sol.maximum69Number(9996) << endl; // 9999
    cout << sol.maximum69Number(9999) << endl; // 9999
    return 0;
}