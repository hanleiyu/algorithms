#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> res(m , 0);
    for(int i = 0; i < m; i ++){
        int value;
        cin >> value;
        res[i] = value;
    }
    int wood = 1;
    for(int i = 0; i < m; i ++){
        int in = 0;
        while(wood != res[i]){
            in ++;
            wood ++;
        }
        wood ++;
        for(int j = 0; j < in; j ++){
            cout << "In,Out,";
        }
        cout << "In";
        if(i != m - 1){
            cout << ",";
        }
    }
    return 0;
}