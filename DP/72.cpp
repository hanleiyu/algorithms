#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m == 0){
            return n;
        }else if(n == 0){
            return m;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; i ++){
            dp[0][i] = i;
        }
        for(int i = 1; i <= m; i ++){
            dp[i][0] = i;
        }
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                if(word2[j - 1] == word1[i - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    string text1 = "abcd";
    string text2 = "abc";
    Solution s;
    cout << s.minDistance(text1, text2);
}