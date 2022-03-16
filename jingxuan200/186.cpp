#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void reverseWords(vector<char>& s) {
        bool flag = false;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == ' '){
                flag = true;
                break;
            }
        }
        if(flag == false){
            return;
        }
        for(int i = 0; i < s.size()/2; i ++){
            char temp = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = temp;
        }

        int i = 0;
        int j = 0;
        while(j < s.size()){
            while(s[j] != ' ' && j < s.size()){
                j ++;
            }
            for(int k = i; k < (j + i)/2; k ++){
                char temp = s[k];
                s[k] = s[j + i - k - 1];
                s[j + i - k - 1] = temp;
            }
            j ++;
            i = j;
        }
    }
};


// class Solution {
// public:
//     void reverseWords(vector<char>& s) {
//         stack<vector<char>> words;
//         int index = 0;
//         while(index < s.size()){
//             vector<char> word;
//             while(index < s.size() && s[index] != ' '){
//                 word.push_back(s[index]);
//                 index ++;
//             }
//             if(words.empty() && index == s.size()){
//                 return;
//             }
//             index ++;
//             words.push(word);
//             word.clear();
//         }
//         s.clear();
//         while(!words.empty()){
//             for(int i = 0; i < words.top().size(); i ++){
//                 s.push_back(words.top()[i]);
//             }
//             words.pop();
//             if(!words.empty()){
//                 s.push_back(' ');
//             }
//         }
//     }
// };