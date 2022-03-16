#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }else if (s.size() == 1){
            return 1;
        }
        auto left = s.begin();
        
        int num = 0;
        int max = 0;
        vector<int> c(128, 0);
        for(auto right = s.begin(); right != s.end(); right ++){
            if(c[*right] == 0){
                c[*right] = 1;
            }else{
                c[*right] ++;
                num ++;
                while(num != 0 && left <= right){
                    if(c[*left] == 2){  
                        num --;
                    }
                    c[*left] --;
                    left ++;
                }
            }
            if(right - left + 1 > max){
                max = right - left + 1;
            }
        }
        return max;
    }
};