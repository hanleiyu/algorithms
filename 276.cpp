class Solution {
public:
    int numWays(int n, int k) {
        if(k == 1){
            if(n < 3){
                return 1;
            }else{
                return 0;
            }
        }
        int way[2];
        way[0] = k;
        way[1] = k + k * (k - 1);
        if(n < 3){
            return way[n - 1];
        }
        for(int i = 2; i < n; i ++){
            way[i % 2] = (way[(i - 2) % 2] + way[(i - 1) % 2]) * (k - 1);
        }
        return way[(n - 1) % 2];
    }
};