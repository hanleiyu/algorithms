#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> num;
        vector<int> differ;
        num.assign(length, 0);
        differ.assign(length, 0);         
        num[0] = differ[0];
        for(int i = 1; i < length; i ++){
            num[i] = num[i - 1] + differ[i];
        }
        return num;
    }
};