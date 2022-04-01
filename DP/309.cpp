#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if(m == 1){
            return 0;
        }else if (m == 2){
            return max(0, prices[1] - prices[0]);
        }
        int d00 = 0;
        int d10 = max(0, prices[1] - prices[0]);
        int d11 = max(- prices[0], - prices[1]);
        for(int i = 2; i < m; i ++){
            int temp = max(d11, d00 - prices[i]);
            d00 = d10;
            d10 = max(d10, d11 + prices[i]);
            d11 = temp;
        }
        return d10;
    }
};