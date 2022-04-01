#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int climb[3] = {0, 1, 2};
        if(n < 3){
            return climb[n];
        }
        for(int i = 3; i <= n; i ++){
            climb[i % 3] = climb[(i - 2) % 3] + climb[(i - 1) % 3];
        }
        return climb[n % 3];
    }
};