#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0;
        int m = prices.size();
        if(m == 1){
            return 0;
        }
        for(int i = 1; i < m; i ++){
            if(prices[i] > prices[i - 1]){
                maxp = max(maxp, prices[i] - prices[i - 1]);
                prices[i] = prices[i - 1];
            }
        }
        return maxp;
    }
};