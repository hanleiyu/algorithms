#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.size() == 1){
            return min(costs[0][0], min(costs[0][1], costs[0][2]));
        }
        vector<int> red;
        vector<int> green;
        vector<int> blue;
        red.push_back(costs[0][0]);
        green.push_back(costs[0][1]);
        blue.push_back(costs[0][2]);
        red.push_back(min(green[0], blue[0]) + costs[1][0]);
        green.push_back(min(red[0], blue[0]) + costs[1][1]);
        blue.push_back(min(green[0], red[0]) + costs[1][2]);
        for(int i = 2; i < costs.size(); i ++){
            red[i % 2] = min(green[(i - 1) % 2], blue[(i - 1) % 2]) + costs[i][0];
            green[i % 2] = min(red[(i - 1) % 2], blue[(i - 1) % 2]) + costs[i][1];
            blue[i % 2] = min(green[(i - 1) % 2], red[(i - 1) % 2]) + costs[i][2];
        }
        return min(red[(costs.size() - 1) % 2], 
        min(green[(costs.size() - 1) % 2], blue[(costs.size() - 1) % 2]));
    }
};