//
// Created by Ruizhe Hou on 2020/10/3.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> a;//提供一对一的hash
        vector<int> b(2, -1);//用来承载结果，初始化一个大小为2，值为-1的容器b
        for (int i = 0; i < nums.size(); i++) {
            if (a.count(target - nums[i])) {
                b[0] = a[target - nums[i]];
                b[1] = i;
                break;
            }
            a[nums[i]] = i;//反过来放入map中，用来获取结果下标
        }
        return b;
    };
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 7, 11, 15};
    auto r1 = sol.twoSum(nums1, 9);
    cout << "[" << r1[0] << ", " << r1[1] << "]" << endl;

    vector<int> nums2 = {3, 2, 4};
    auto r2 = sol.twoSum(nums2, 6);
    cout << "[" << r2[0] << ", " << r2[1] << "]" << endl;

    vector<int> nums3 = {3, 3};
    auto r3 = sol.twoSum(nums3, 6);
    cout << "[" << r3[0] << ", " << r3[1] << "]" << endl;

    return 0;
}
