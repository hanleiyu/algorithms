#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int shortestWay(string source, string target) {
        int i = 0;
        int ans = 0;
        while(i < target.size()){
            bool flag = false;
            int j = 0;
            while(j < source.size() && i < target.size()){
                if(source[j] == target[i]){
                    j ++;
                    i ++;
                    flag = true;
                }else{
                    j ++;
                }
            }
            if(flag){
                ans ++;
            }else{
                return -1;
            }
        }
        return ans;
    }
};