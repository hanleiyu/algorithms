#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int num_min = arrays[0][0];
        int num_max = arrays[0].back();
        int dis = 0;
        for(int i = 1; i < arrays.size(); i ++){
            dis = max(dis, max((arrays[i].back() - num_min), (num_max - arrays[i][0])));
            num_min = min(arrays[i][0], num_min);
            num_max = max(arrays[i].back(), num_max);
        }
        return dis;
    }
};