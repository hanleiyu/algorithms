#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        //只有一个数
        if(nums.size() == 1){
            return nums[0];
        }
        sort(nums.begin(), nums.end(), cmp);
        int i = 0;
        while(1){
            bool flag = false;
            int j = i + 1;
            for(; j < nums.size(); j ++){
                if(nums[j] != nums[i]){
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                return -1;
            }else{
                if(j == i + 1){
                    return nums[i];
                }else{
                    i = j;
                    //最后一个数
                    if(i == nums.size() - 1){
                        return nums[i];
                    }
                }
            }
        }
    }
};