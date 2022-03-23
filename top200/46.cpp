#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void swap(vector<int>& nums, int p1, int p2){
        if(p1 != p2){
            int temp = nums[p1];
            nums[p1] = nums[p2];
            nums[p2] = temp;
        }
    }

    void helper(vector<int>& nums, int index){
        int size = nums.size();
        if(index == size - 1){
            res.push_back(nums);
            return;
        }
        for(int i = index; i < size; i ++){
            swap(nums, index, i);
            helper(nums, index + 1);
            swap(nums, index, i);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0);
        return res;
    }
};