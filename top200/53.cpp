#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int max_sum = 0;
        int sum = 0;
        for(auto it = nums.begin(); it != nums.end(); it ++){
            if(it == nums.begin()){
                max_sum = *it;
                sum = *it;
                continue;
            }
            sum = max(sum + *it, *it);
            max_sum = max(max_sum, sum);  
        }
        return max_sum;
    }
};