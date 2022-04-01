#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int m = cost.size();
        int dp[2] = {0, 0};
        for(int i = 2; i <= m; i ++){
            dp[i % 2] = min(dp[(i - 1) % 2] + cost[i - 1], dp[(i - 2) % 2] + cost[i - 2]);
        }
        return dp[m % 2];
    }
};