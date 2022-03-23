#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void helper(vector<int>& nums, vector<int>& subset, int target, int index){
        if(target == 0){
            res.push_back(subset);
            return;
        }else if (target > 0 && index < nums.size()){
            helper(nums, subset, target, index + 1);
            subset.push_back(nums[index]);
            helper(nums, subset, target- nums[index], index);
            subset.pop_back();          
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subset;
        helper(candidates, subset, target, 0);
        return res;
    }
};