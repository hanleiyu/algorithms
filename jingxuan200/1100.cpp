#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int num = 0;
        if(s.size() >= k){
            int i = 0;
            int j = 0;    
            vector<int> word;
            word.assign(26, -1);
            while(j < s.size()){
                while((j - i) <= k-1){
                    if(word[s[j] - 'a'] != -1){  
                        for(int n = i; n < word[s[j] - 'a']; n ++){
                            word[s[n] - 'a'] = -1;
                        }
                        i = word[s[j] - 'a'] + 1;
                    }
                    word[s[j] - 'a'] = j;
                    j ++;
                    if(j == s.size()){
                        if((j - i) == k-1){
                            num ++;
                        }
                        return num;
                    }
                }
                num ++;
                word[s[j - k] - 'a'] = -1;
                i ++;  
            }
        }
        return num;
    }
};