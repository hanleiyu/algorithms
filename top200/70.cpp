#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }else if (n == 2){
            return 2;
        }
        int num[2] = {1, 2};
        for(int i = 3; i <= n; i ++){
            num[(i - 1) % 2] = num[0] + num[1];
        }
        return num[(n - 1) % 2];
    }
};