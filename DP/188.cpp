#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k == 0){
            return 0;
        }
        int m = prices.size();
        if(m < 2){
            return 0;
        }else if (m == 2){
            return max(0, prices[1] - prices[0]);
        }
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(k + 1, vector<int>(2, 0)));        
        dp[0][1][0] = -1000;
        dp[0][1][1] = -prices[0];
        for(int j = 2; j <= k; j ++){
            dp[0][j][0] = -1000;
            dp[0][j][1] = -1000;
        }
        for(int i = 1; i < m; i ++){
            for(int j = 1; j <= k; j ++){
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }       
        }
        int maxp = 0;
        for(int j = 1; j <= k; j ++){
            if(dp[m - 1][j][0] > maxp){
                maxp = dp[m - 1][j][0];
            }
        }
        return maxp;
    }
};