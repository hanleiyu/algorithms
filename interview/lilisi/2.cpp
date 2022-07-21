#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @param k int整型 
     * @return long长整型
     */
    long long ans(vector<int>& array, int k) {
        // write code here
        int size = array.size();
        int sum = 0;
        for(int i = 0; i < size; i ++){
            for(int j = i + 1; j < size; j ++){
                if(array[i] + array[j] <= k){
                    sum ++;
                }
            }
        }
        return sum;
    }
};