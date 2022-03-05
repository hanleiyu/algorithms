#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> word;
        word.assign(26, 0);
        for(int i = 0; i < s.size(); i ++){
            word[s[i]-'a'] ++;
        }
        int flag = 0;
        for(int i = 0; i < 26; i ++){
            if(word[i] % 2 == 1){
                flag ++;
            }
            if(flag > 1){
                return false;
            }
        }
        return true;
    }
};