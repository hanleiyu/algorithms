#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void helper(vector<int>& nums, vector<int>& subset, int index){
        if(index == nums.size()){
            res.push_back(subset);
            return;
        }
        helper(nums, subset, index + 1);
        subset.push_back(nums[index]);
        helper(nums, subset, index + 1);
        subset.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        helper(nums, subset, 0);
        return res;
    }
};