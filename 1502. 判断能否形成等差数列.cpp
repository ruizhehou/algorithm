//
// Created by Ruizhe Hou on 2020/10/12.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size() - 1; i++)
            if (arr[i] - arr[i - 1] != arr[i + 1] - arr[i]) return false;
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {3, 5, 1};
    cout << sol.canMakeArithmeticProgression(arr1) << endl; // 1
    vector<int> arr2 = {1, 2, 4};
    cout << sol.canMakeArithmeticProgression(arr2) << endl; // 0
    return 0;
}
