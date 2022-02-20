#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> missing;
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] == lower){
                lower ++ ;
            }else if((nums[i] - lower) == 1){
                missing.push_back(to_string(lower));
                lower = nums[i] + 1;
            }else{
                missing.push_back(to_string(lower) + "->" + to_string(nums[i] - 1));
                lower = nums[i] + 1;
            }
        }
        if(lower != upper + 1){
            if(upper == lower){
                missing.push_back(to_string(lower));
            }else{
                missing.push_back(to_string(lower) + "->" + to_string(upper));
            }
        }
        return missing;
    }
};