#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int sum = 0;
        for(int i = 0; i < data.size(); i ++){
            if(data[i] == 1){
                sum ++;
            }
        }
        if(sum <= 1){
            return 0;
        }
        int max_num = 0;
        int num = 0;
        for(int i = 0; i < data.size(); i ++){
            if(i < sum){
                num += data[i];
                max_num = num;
                continue;
            }
            num = num + data[i] - data[i - sum];
            max_num = max(max_num, num);
        }
        return sum - max_num;
    }
};