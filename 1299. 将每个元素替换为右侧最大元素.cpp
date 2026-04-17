//
// Created by Ruizhe Hou on 2020/10/7.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int> &arr) {
        int m = -1, tmp;
        for (int i = arr.size() - 1; i >= 0; i--) {
            tmp = arr[i];
            arr[i] = m;
            m = tmp > m ? tmp : m;
        }
        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {17, 18, 5, 4, 6, 1};
    auto res = sol.replaceElements(arr);
    for (int v : res) cout << v << " ";
    cout << endl; // 18 6 6 6 1 -1
    return 0;
}