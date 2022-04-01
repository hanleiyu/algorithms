#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> sub;
        sub.push_back(vector<int>(m, 1));
        sub.push_back(vector<int>(m, 0));
        for(int i = 0; i < m; i ++){
            if(text1[i] != text2[0]){
                sub[0][i] = 0;
            }else{
                break;
            }
        }
        for(int i = 1; i < n; i ++){
            if(text1[0] == text2[i]){
                sub[i % 2][0] = 1;
            }
            for(int j = 1; j < m; j ++){
                if(text1[j] == text2[i]){
                    sub[i % 2][j] = sub[(i - 1) % 2][j - 1] + 1;                  
                }else{
                    sub[i % 2][j] = max(sub[i % 2][j - 1], sub[(i - 1) % 2][j]);
                }
            }
        }
        return sub[(n - 1) % 2][m - 1];
    }
};

int main(){
    Solution s;
    string text1 = "bsbininm";
    string text2 = "jmjkbkjkv";
    cout << s.longestCommonSubsequence(text1, text2);
}