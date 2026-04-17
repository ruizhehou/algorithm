//
// Created by Ruizhe Hou on 2020/10/12.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr) {
        vector<int> v(1001, 0);
        for (int i = 0; i < target.size(); i++) {
            v[target[i]]++;
            v[arr[i]]--;
        }
        for (int i = 1; i <= 1000; i++) {
            if (v[i] != 0)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> t1 = {1, 2, 3, 4}, a1 = {2, 4, 1, 3};
    cout << sol.canBeEqual(t1, a1) << endl; // 1
    vector<int> t2 = {7}, a2 = {1};
    cout << sol.canBeEqual(t2, a2) << endl; // 0
    return 0;
}
