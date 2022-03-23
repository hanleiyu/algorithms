#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.empty() || text2.empty()){
            return 0;
        }
        vector<vector<int>> dp;
        int size1 = text1.size();
        int size2 = text2.size();
        dp.push_back(vector<int> (size1, 0));
        dp.push_back(vector<int> (size1, 0));
        if(text1[0] == text2[0]){
            dp[0][0] = 1;
        }
        for(int j = 1; j < size1; j ++){
            int temp = 0;
            if(text1[j] == text2[0]){
                temp = 1;
            }
            dp[0][j] = min(dp[0][j - 1] + temp, 1);
        }
        for(int i = 1; i < size2; i ++){
            int temp = 0;
            if(text1[0] == text2[i]){
                temp = 1;
            }
            dp[i % 2][0] = min(dp[(i - 1) % 2][0] + temp, 1);
            for(int j = 1; j < size1; j ++){
                if(text1[j] == text2[i]){
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                }else{
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
                }   
            }
        }
        return dp[(size2 - 1) % 2][size1 - 1];
    }
};         