//
// Created by Ruizhe Hou on 2020/10/6.
//
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>> &paths) {
        set<string> from;
        string res;
        for (auto path : paths) {
            from.insert(path[0]);
        }
        for (auto path : paths) {
            if (!from.count(path[1]))
                return path[1];
        }
        return "";
    }
};

int main() {
    Solution sol;
    vector<vector<string>> paths = {{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
    cout << sol.destCity(paths) << endl; // Sao Paulo
    return 0;
}