#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        int dpi10 = -100000;
        int dpi11 = -prices[0];
        int dpi20 = -100000;
        int dpi21 = -100000;
        for(int i = 1; i < m; i ++){
            dpi20 = max(dpi20, dpi21 + prices[i]);
            dpi21 = max(dpi21, dpi10 - prices[i]);
            dpi11 = max(dpi11, - prices[i]);
            dpi10 = max(dpi10, dpi11 + prices[i]);
        }
        return max(0, max(dpi10, dpi20));
    }
};