#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        int len = 1;
        int size = nums.size();
        vector<int> d(size + 1);
        d[1] = nums[0];
        for(int i = 1; i < size; i ++){
            if(nums[i] > d[len]){
                d[++len] = nums[i];
            }else{
                int left = 1;
                int right = len; 
                int pos = 0;
                while(left <= right){
                    int mid = (left + right) >> 1;
                    if(d[mid] >= nums[i]){
                        right = mid - 1;
                    }else{
                        pos = mid;
                        left = mid + 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};