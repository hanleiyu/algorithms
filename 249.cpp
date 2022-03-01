#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;
        unordered_map<string, int> res;
        int index = 0;

        if(strings.size() > 0){
            for(int i = 0; i < strings.size(); i ++){
                string temp = strings[i];
                if(temp[0] != 'a'){
                    for(int n = 1; n < temp.size(); n ++){
                        // a 左移是 z
                        temp[n] = (temp[n] - temp[0] + 26) % 26 + 'a';
                    }
                    temp[0] = 'a';
                }

                if(res.find(temp) != res.end()){
                    result[res[temp]].push_back(strings[i]);
                    continue;
                }
                res[temp] = index++;
                result.push_back({strings[i]});
            }
        }
        return result;
    }
};