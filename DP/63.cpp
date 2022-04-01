#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> mpath(m, 0);
        vector<int> npath(n, 0);
        for(int i = 0; i < n; i ++){
            if(obstacleGrid[0][i] == 0){
                npath[i] = 1;
            }else{
                break;
            }
        }
        for(int i = 0; i < m; i ++){
            if(obstacleGrid[i][0] == 0){
                mpath[i] = 1;
            }else{
                break;
            }
        }
        for(int i = 1; i < m; i ++){
            npath[0] = mpath[i];
            for(int j = 1; j < n; j ++){
                if(obstacleGrid[i][j] == 1){
                    npath[j] = 0;
                }else{
                    npath[j] += npath[j - 1];
                }
                
            }
        }
        return npath[n - 1];
    }
};