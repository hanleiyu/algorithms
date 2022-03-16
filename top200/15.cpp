#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res = {};
        if(nums.size() < 3){
            return res;
        }
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int a = 0; a < size - 2; a ++){
            if(a > 0 && nums[a] == nums[a - 1]){
                continue;
            }
            int left = a + 1;
            int right = size - 1;
            while(left < right){
                int result = nums[left] + nums[right];
                if(result < -nums[a]){
                    while(nums[left + 1] == nums[left] && left < right - 1){
                        left ++;
                    }
                    left ++;
                }else if(result > -nums[a]){
                    while(nums[right - 1] == nums[right] && left < right - 1){
                        right --;
                    }
                    right --;
                }else{
                    res.push_back({nums[a], nums[left], nums[right]});
                    while(nums[left + 1] == nums[left] && left < right - 1){
                        left ++;
                    }
                    while(nums[right - 1] == nums[right] && left < right - 1){
                        right --;
                    }
                    left ++;
                    right --;
                }
            }
        }
        return res;
    }
};