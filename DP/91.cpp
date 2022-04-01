#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int m = s.size();        
        if(s[0] == '0'){
            return 0;
        }
        if(m == 1){
            return 1;
        }
        int dp[2] = {1, 1};
        if((s[0] - '0') * 10 + s[1] - '0' <= 26){
            if(s[1] != '0'){
                dp[1] = 2;
            }            
        }else if (s[1] == '0'){
            return 0;
        }
        for(int i = 2; i < m; i ++){
            if(s[i] == '0'){
                if(s[i - 1] != '1' && s[i - 1] != '2'){
                    return 0;
                }else{
                    dp[(i - 1) % 2] = dp[(i - 2) % 2];
                    dp[i % 2] = dp[(i - 1) % 2];
                }
            }else if(s[i - 1] == '0'){
                dp[i % 2] = dp[(i - 1) % 2];
            }else if ((s[i - 1] - '0') * 10 + s[i] - '0' <= 26){
                dp[i % 2] = dp[(i - 1) % 2] + dp[(i - 2) % 2];                               
            }else{
                dp[i % 2] = dp[(i - 1) % 2];
            }
        }
        return dp[(m - 1) % 2];
    }
};

int main(){
    string text = "1201";
    Solution s;
    cout << s.numDecodings(text);
}