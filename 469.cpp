#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        int pre = 0;
        for(int i = 0; i < n; i ++){
            int x1 = points[(i + 1) % n][0] - points[i][0];
            int x2 = points[(i + 2) % n][0] - points[i][0];
            int y1 = points[(i + 1) % n][1] - points[i][1];
            int y2 = points[(i + 2) % n][1] - points[i][1];
            int cur = x1 * y2 - x2 * y1;
            if(cur != 0){
                if((cur > 0 && pre < 0) || (cur < 0 && pre > 0)){
                    return false;
                }else{
                    pre = cur;
                }
            }
        }
        return true;
    }
};