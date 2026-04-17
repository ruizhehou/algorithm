//
// Created by Ruizhe Hou on 2020/9/17.
//
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    double soupServings(int N) {
        if (N >= 4800) {//N超过了4800，结果与1分厂接近
            return 1;
        }
        int myN = (int) ceil(N / 25.0);//缩小为原来的25分之一
        //dp[i][j]表示:当给定i毫升的A和j毫升的B，汤A先分配完的概率 + 汤A和汤B同时分配完的概率 / 2
        vector<vector<double>> dp(myN + 1, vector<double>(myN + 1, 0));
        dp[0][0] = 0.5;//特殊情况，0毫升A、0毫升B（同时分配完 1 * 0.5）
        for (int i = 1; i < myN + 1; ++i) {
            dp[i][0] = 0;//i毫升A，0毫升B，则B必定先分配完，不可能出现A先分配完或者A、B同时分配完
            dp[0][i] = 1;//0毫升A，i毫升B，则A必定先分配完，概率为1
        }
        //开始动态规划
        for (int i = 1; i < myN + 1; ++i) {
            int a1 = i - 4 > 0 ? i - 4 : 0;//不足4，按4算（实际上是不足100，按100算，然后分配完了，没有剩余）
            int a2 = i - 3 > 0 ? i - 3 : 0;//不足3，按3算（实际上是不足75，按75算，然后分配完了，没有剩余）
            int a3 = i - 2 > 0 ? i - 2 : 0;//不足2，按2算（实际上是不足50，按75算，然后分配完了，没有剩余）
            int a4 = i - 1 > 0 ? i - 1 : 0;//不足1，按1算（实际上是不足25，按25算，然后分配完了，没有剩余）
            for (int j = 1; j < myN + 1; ++j) {
                int b1 = j;
                int b2 = j - 1 > 0 ? j - 1 : 0;//不足1，按1算（实际上是不足25，按25算，然后分配完了，没有剩余）
                int b3 = j - 2 > 0 ? j - 2 : 0;//不足2，按2算（实际上是不足50，按75算，然后分配完了，没有剩余）
                int b4 = j - 3 > 0 ? j - 3 : 0;//不足3，按3算（实际上是不足75，按75算，然后分配完了，没有剩余）
                //状态转移方程：dp[i][j] = 0.25 * (dp[i-100][j] + dp[i-75][j-25] + dp[i-50][j-50] + dp[i-75][j-25])
                //将N缩小为原来的25分之一的转移方程：dp[i][j] = 0.25 * (dp[i-4][j] + dp[i-3][j-1] + dp[i-2][j-2] + dp[i-3][j-1])
                dp[i][j] = 0.25 * (dp[a1][b1] + dp[a2][b2] + dp[a3][b3] + dp[a4][b4]);
            }
        }
        return dp[myN][myN];
    }
};

int main() {
    Solution sol;
    printf("%.5f\n", sol.soupServings(50));  // 0.62500
    printf("%.5f\n", sol.soupServings(100)); // 0.71875
    return 0;
}