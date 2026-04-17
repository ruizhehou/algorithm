//
// Created by houruizhe on 2020/10/19.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(nums[i]) && i - m[nums[i]] <= k) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> n1 = {1, 2, 3, 1};
    cout << sol.containsNearbyDuplicate(n1, 3) << endl; // 1
    vector<int> n2 = {1, 0, 1, 1};
    cout << sol.containsNearbyDuplicate(n2, 1) << endl; // 1
    vector<int> n3 = {1, 2, 3, 1, 2, 3};
    cout << sol.containsNearbyDuplicate(n3, 2) << endl; // 0
    return 0;
}