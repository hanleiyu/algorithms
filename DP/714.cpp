#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int m = prices.size();
        if(m == 1){
            return 0;
        }else if (m == 2){
            return max(0, prices[1] - prices[0] - fee);
        }
        int dpi0 = 0;
        int dpi1 = -prices[0];
        for(int i = 1; i < m; i ++){
            int tempi0 = max(dpi0, dpi1 + prices[i] - fee);
            int tempi1 = max(dpi1, dpi0 - prices[i]);
            dpi0 = tempi0;
            dpi1 = tempi1;
        }
        return dpi0;
    }
};