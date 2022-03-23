#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp;
        int weight = grid[0].size();
        int height = grid.size();
        dp.push_back(vector<int> (weight, 0));
        dp.push_back(vector<int> (weight, 0));
        dp[0][0] = grid[0][0];
        for(int j = 1; j < weight; j ++){
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for(int i = 1; i < height; i ++){
            dp[i % 2][0] = dp[(i - 1) % 2][0] + grid[i][0];
            for(int j = 1; j < weight; j ++){
                dp[i % 2][j] = min(dp[i % 2][j - 1], dp[(i - 1) % 2][j]) + grid[i][j];
            }
        }
        return dp[(height - 1) % 2][weight - 1];
    }
};