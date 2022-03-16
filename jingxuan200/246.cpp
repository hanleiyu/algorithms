#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int i = 0;
        int j = num.size() - 1;
        while(i < j){
            if(num[i] == num[j]){
                if(num[i] != '0' && num[i] != '1' && num[i] != '8'){
                    return false;
                }
            }else{
                if(!((num[i] == '6' && num[j] == '9') || (num[i] == '9' && num[j] == '6'))){
                    return false;
                }
            }
            i ++;
            j --;
        }
        if(i == j && num[i] != '0' && num[i] != '1' && num[i] != '8'){
            return false;
        }
        return true;
    }
};