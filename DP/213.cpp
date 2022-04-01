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
        }else if (m == 2){
            return max(nums[0], nums[1]);
        }
        int pre = 0;
        int now = nums[1];
        for(int i = 2; i < m; i ++){
            int temp = max(pre + nums[i], now);
            pre = now;
            now = temp;
        }
        int max_num = now;
        pre = 0;
        now = nums[0];
        for(int i = 1; i < m - 1; i ++){
            int temp = max(pre + nums[i], now);
            pre = now;
            now = temp;
        }
        max_num = max(max_num, now);
        return max_num;
    }
};

int main(){
    Solution s;
    vector<int> a = {4,1,2,7,5,3,1};
    s.rob(a);
    return 0;
}