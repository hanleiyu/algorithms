#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> path(n, 1);
        for(int i = 1; i < m; i ++){
            for(int j = 1; j < n; j ++){
                path[j] += path[j - 1];
            }
        }
        return path[n - 1];
    }
};

int main(){
    Solution s;
    int m = 3;
    int n = 7;
    cout << s.uniquePaths(m, n);
    return 0;
}