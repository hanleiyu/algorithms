#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    int sum = 0;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            int num;
            cin >> num;
            if(i == (x - 1) && j == (y - 1)){
                sum ++;                
            }else{
                sum += num;
            }
        }
    }
    cout << sum;
    return 0;
}