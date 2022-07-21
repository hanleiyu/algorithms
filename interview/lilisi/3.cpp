#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param a int整型vector 
     * @return long长整型
     */
    long long minimum(vector<int>& a) {
        // write code here
        int num = INT_MAX;
        int size = a.size();
        int sum = 0;
        for(int i = 0; i < size; i ++){
            sum += a[i];
        }
        int left = 0;
        int right = 0;
        int half = 0;
        while(left <= right && right < size){
            while(2 * half < sum && right < size){
                num = min(num, sum - half*2);
                if(num == 0){
                    return 0;
                }
                half += a[right];
                right ++;
            }            
            while(2 * half >= sum && left <= right){
                num = min(num, half*2 - sum);
                if(num == 0){
                    return 0;
                }
                half -= a[left];
                left ++;
            }
            num = min(num, sum - half*2);
            if(num == 0){
                return 0;
            }
        }        
        return num;
    }
};
int main(){
    vector<int> a = {1,2,3,4,5};
    Solution s;
    cout << s.minimum(a);
    return 0;
}

// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 
//      * @param a int整型vector 
//      * @return long长整型
//      */
//     long long minimum(vector<int>& a) {
//         // write code here
//         int num = INT_MAX;
//         int size = a.size();
//         int sum = 0;
//         for(int i = 0; i < size; i ++){
//             sum += a[i];
//         }        
//         for(int i = 0; i < size - 1; i ++){
//             int left = 0;
//             for(int j = i; j < size - 1; j ++){
//                 left += a[j];
//                 if(left *2 <= sum && (left + a[j + 1])*2 >= sum){
//                     int temp = sum - left*2;
//                     num = min(num, temp);
//                     if(num == 0){
//                         return 0;
//                     }
//                     break;
//                 }
//             }            
//         }
//         return num;
//     }
// };

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param a int整型vector 
     * @return long长整型
     */
    long long minimum(vector<int>& a) {
        // write code here
        int num = INT_MAX;
        int size = a.size();
        int sum = 0;
        for(int i = 0; i < size; i ++){
            sum += a[i];
        }        
        for(int i = 0; i < size - 1; i ++){
            int left = 0;
            for(int j = i; j < size - 1; j ++){
                left += a[j];
                int temp = sum - left*2;
                if(temp < 0){
                    temp *= -1;
                }
                num = min(num, temp);
                if(num == 0){
                    return 0;
                }
            }            
        }
        return num;
    
    }
};
