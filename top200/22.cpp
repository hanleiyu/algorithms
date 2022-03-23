#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> res;

    void helper(int left, int right, string s){
        if(left == 0 && right == 0){
            res.push_back(s);
            return;
        }

        if(left > 0){
            helper(left - 1, right, s + "(");
        }
        if(left < right){
            helper(left, right - 1, s + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        helper(n, n, "");
        return res;
    }
};