//
// Created by Ruizhe Hou on 2020/9/26.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */

    int minDistance(string word1, string word2, int k) {
        int m = word1.size();
        int n = word2.size();
        if (m - n > k || n - m > k) return k + 1;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                }
            }
        }
        return dp[m][n];
    }

    vector<string> kDistance(vector<string> &words, string &target, int k) {
        // write your code here
        vector<string> res;
        for (auto &word: words) {
            if (minDistance(word, target, k) <= k) {
                res.push_back(word);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"abc", "abd", "abcd", "adc"};
    string target = "abc";
    auto res = sol.kDistance(words, target, 1);
    for (auto &w : res) cout << w << " ";
    cout << endl;
    return 0;
}
