#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 1){
            return 0;
        }
        stack<int> h;
        int sum = 0;
        int size = height.size();
        for(int i = 0; i < size; i ++){

        }
        return sum;
    }
};