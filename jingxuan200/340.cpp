#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0){
            return 0;
        }
        int left = 0;
        int right = 0;
        int max = 0;
        unordered_map<char, int> word;
        for(int i = 0; i < s.size(); i ++){
            right ++;
            char c;
            if(word.find(s[i]) == word.end() && word.size() == k){
                if(k == 1){
                    c = s[left];                    
                }else{
                    c = word.begin()->first;
                    for(unordered_map<char, int>::iterator it = word.begin(); it != word.end(); it ++){
                        if(it->second < word[c]){
                            c = it->first;
                        }
                    }
                }                
                left = word[c] + 1;
                word.erase(c);
            }
            word[s[i]] = i;            
            if((right - left) > max){
                max = right - left;
            }
        }
        return max;
    }
};