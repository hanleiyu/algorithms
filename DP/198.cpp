#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int m = nums.size();
        if(m == 1){
            return nums[0];
        }
        nums[1] = max(nums[0], nums[1]);
        int max_rob = nums[1];
        for(int i = 2; i < m; i ++){
            nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);        
            max_rob = max(max_rob, nums[i]);
        }
        return max_rob;
    }
};