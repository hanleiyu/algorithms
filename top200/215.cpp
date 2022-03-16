#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto it = nums.begin(); it != nums.end(); it ++){
            if(q.size() < k){
                q.push(*it);
            }else if (*it > q.top()){
                q.pop();
                q.push(*it);
            }
        }
        return q.top();
    }
};