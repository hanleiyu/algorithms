#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void swap(vector<int>& nums, int p1, int p2){
        if(p1 != p2){
            int temp = nums[p1];
            nums[p1] = nums[p2];
            nums[p2] = temp;
        }
    }

    int partition(vector<int>& nums, int begin, int end){
        swap(nums, rand() % (end - begin) + begin, end);
        int small = begin - 1;
        for(int i = begin; i < end; i ++){
            if(nums[i] < nums[end]){
                small ++;
                swap(nums, small, i);
            }
        }
        small ++;
        swap(nums, small, end);
        return small;
    }

    void quickSort(vector<int>& nums, int begin, int end){
        if(begin < end){
            int index = partition(nums, begin, end);
            quickSort(nums, begin, index - 1);
            quickSort(nums, index + 1, end);
        }
        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};