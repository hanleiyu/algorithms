#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestFactorization(int num) {
        if(num < 10){
            return num;
        }
        int factor_num[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        int factor[4] = {2, 3, 5, 7};
        for(int i = 0; i < 4; i ++){
            while(num % factor[i] == 0){
                factor_num[factor[i] - 2]++;
                num /= factor[i];
            }
        }
        if(num != 1){
            return 0;
        }
        if(factor_num[1] >= 2 ){
            factor_num[7] = factor_num[1] / 2;
            factor_num[1] %= 2;
        }
        if(factor_num[0] >= 3 ){
            factor_num[6] = factor_num[0] / 3;
            factor_num[0] %= 3;
        }
        if(factor_num[1] != 0 && factor_num[0] != 0){
            factor_num[4] = min(factor_num[0], factor_num[1]);
            factor_num[0] -= factor_num[4];
            factor_num[1] -= factor_num[4];
        }
        if(factor_num[0] > 1 ){
            factor_num[2] = 1;
            factor_num[0] = 0;
        }
        long long int result = 0;
        for(int i = 0; i < 8; i ++){
            while(factor_num[i] != 0){
                if(result == 0){
                    result = i + 2;
                }else{
                    result = result * 10 + i + 2;
                    if(result > INT_MAX){
                        return 0;
                    }
                }
                factor_num[i] --;
            }
        }
        return result;
    }
};