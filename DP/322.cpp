#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        int max_num = amount + 1;
        int m = coins.size();
        vector<int> num(amount + 1, max_num);
        num[0] = 0;
        for(int i = 1; i <= amount; i ++){
            for(int j = 0; j < m; j ++){
                if(coins[j] <= i){
                    num[i] = min(num[i], num[i - coins[j]] + 1);
                }                
            }
        }
        return num[amount] > amount ? -1 : num[amount];
    }
};

int main(){
    vector<int> coins = {1, 2, 5};
    Solution s;
    s.coinChange(coins, 11);
}