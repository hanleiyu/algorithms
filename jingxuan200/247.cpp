#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> result;
    vector<char> nums_all = {'0', '1', '8', '6', '9'};
    vector<char> nums_single = {'0', '1', '8'};

    void word(string s, int n){
        if(s.size() < n/2){
            for(auto num: nums_all){
                if(s.size() == 0 && num == '0'){
                    continue;
                }
                s.push_back(num);
                word(s, n);
                s.pop_back();
            }
        }else{
            if(n % 2 == 1){
                for(auto num: nums_single){
                    s.push_back(num);
                    string re = s;
                    for(int i = s.size() - 2; i >= 0; i --){
                        if(s[i] == '0' || s[i] == '1' || s[i] == '8'){
                            re.push_back(s[i]);
                        }else if (s[i] == '6'){
                            re.push_back('9');
                        }else if (s[i] == '9'){
                            re.push_back('6');
                        }
                    }
                    result.push_back(re);
                    s.pop_back();
                }
            }else{
                string re = s;
                for(int i = s.size() - 1; i >= 0; i --){
                    if(s[i] == '0' || s[i] == '1' || s[i] == '8'){
                        re.push_back(s[i]);
                    }else if (s[i] == '6'){
                        re.push_back('9');
                    }else if (s[i] == '9'){
                        re.push_back('6');
                    }
                }
                result.push_back(re);
            }
        }
    }
    vector<string> findStrobogrammatic(int n) {
        if(n == 1){
            result.push_back("0");
            result.push_back("1");
            result.push_back("8");
            return result;
        }
        string s = "";
        word(s, n);
        return result;
    }
};