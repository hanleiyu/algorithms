#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = nums.size();
        int maxsub = nums[0];
        for(int i = 1; i < m; i ++){
            nums[i] = max(nums[i], nums[i - 1] + nums[i]);
            maxsub = max(maxsub, nums[i]);
        }
        return maxsub;
    }
};