#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> result;
        int i = 0;
        while(i < currentState.size()){
            if(currentState[i] == '-'){
                i ++;
            }else{
                if(currentState[i + 1] == '+'){
                    string next = currentState;
                    next[i] = '-';
                    next[i + 1] = '-';
                    result.push_back(next);
                    i ++;    
                }else{
                    i += 2;
                }
            }
        }
        return result;
    }
};