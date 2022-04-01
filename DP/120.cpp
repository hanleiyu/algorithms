#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if(m == 1){
            return triangle[0][0];
        }
        for(int i = 1; i < m; i ++){
            triangle[i][0] +=  triangle[i - 1][0];
            int prelevel = triangle[i - 1].size();
            int thislevel = triangle[i].size();
            for(int j = 1; j < thislevel; j ++){
                if(j > prelevel - 1){
                    triangle[i][j] += triangle[i- 1][j - 1];
                }else{
                    triangle[i][j] += min(triangle[i- 1][j - 1], triangle[i - 1][j]);
                }
            }
        }
        int minT = triangle[m - 1][0];
        int n = triangle[m - 1].size();
        for(int i = 0; i < n; i ++){
            if(triangle[m - 1][i] < minT){
                minT = triangle[m - 1][i];
            }
        }
        return minT;
    }
};