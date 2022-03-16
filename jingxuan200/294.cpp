#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canWin(string currentState) {
        int n = currentState.size();
        for(int i = 0; i < n - 1; i ++){
            if(currentState[i] == '+' && currentState[i + 1] == '+'){
                currentState[i] = '-';
                currentState[i + 1] = '-';
                if(canWin(currentState) == false){
                    return true;
                }
                currentState[i] = '+';
                currentState[i + 1] = '+';
            }
        }
        return false;
    }
};