#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if(size == 0 || size == 1){
            return s;
        }
        int left = 0;
        int right = 0;
        if(size % 2 == 0){
            right = size / 2;
            left = right - 1;
        }else{
            left = size / 2 - 1;
            right = left + 2;
        }
        while(s[left] == s[right] && left >= 0 && right < size){
            left --;
            right ++;
        }
        string res = s.substr(left + 1, right - left - 1);
        string resL = longestPalindrome(s.substr(0, left + 1));
        string resR = "";
        if(right < size){
            string resR = longestPalindrome(s.substr(right));
        }        
        int max_size = max(res.size(), max(resL.size(), resR.size()));
        if(res.size() == max_size){
            return res;
        }else if (resL.size() == max_size){
            return resL;
        }else{
            return resR;
        }
    }
};

int main(){
    string s = "bb";
    Solution ex;
    cout << ex.longestPalindrome(s);
    return 0;
}

// class Solution {
// public:
//     pair<int, int> expandAroundCenter(const string& s, int left, int right) {
//         while (left >= 0 && right < s.size() && s[left] == s[right]) {
//             --left;
//             ++right;
//         }
//         return {left + 1, right - 1};
//     }

//     string longestPalindrome(string s) {
//         int start = 0, end = 0;
//         for (int i = 0; i < s.size(); ++i) {
//             auto [left1, right1] = expandAroundCenter(s, i, i);
//             auto [left2, right2] = expandAroundCenter(s, i, i + 1);
//             if (right1 - left1 > end - start) {
//                 start = left1;
//                 end = right1;
//             }
//             if (right2 - left2 > end - start) {
//                 start = left2;
//                 end = right2;
//             }
//         }
//         return s.substr(start, end - start + 1);
//     }
// };