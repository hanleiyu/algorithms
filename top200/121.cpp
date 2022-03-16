#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if(prices.size() == 1){
            return profit;
        }
        stack<int> s;
        for(auto it = prices.begin(); it != prices.end(); it ++){
            if(s.empty() || *it < s.top()){
                s.push(*it);
            }else{
                profit = max(profit, *it - s.top());
            }
        }
        return profit;
    }
};