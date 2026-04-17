//
// Created by Ruizhe Hou on 2020/10/7.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int p0 = 0, p2 = nums.size() - 1;
        int i = 0;
        while (i <= p2) {
            if (nums[i] == 0) {
                nums[i] = nums[p0];
                nums[p0] = 0;
                p0++;
                i++;
            } else if (nums[i] == 2) {
                nums[i] = nums[p2];
                nums[p2] = 2;
                p2--;
            } else i++;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);
    for (int v : nums) cout << v << " ";
    cout << endl; // 0 0 1 1 2 2
    return 0;
}
