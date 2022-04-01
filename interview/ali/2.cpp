#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> num(3, 0);
    for(int i = 0; i < n; i ++){
        string s;
        cin >> s;
        int size = s.length();
        for(int j = 0; j < size; j ++){
            if(s[j] == 'A'){
                num[0] ++;
            }else if (s[j] == 'L'){
                num[1] ++;
            }else if (s[j] == 'I'){
                num[2] ++;
            }
        }
        if(num[0] == 0 && num[1] == 0 && num[2] == 0){
            cout << -1;
            if(i != n - 1){
                cout << endl;
            }
        }else{
            while(num[0] != 0 || num[1] != 0 || num[2] != 0){
                if(num[0] != 0){
                    cout << 'A';
                    num[0] --;
                }
                if(num[1] != 0){
                    cout << 'L';
                    num[1] --;
                }
                if(num[2] != 0){
                    cout << 'I';
                    num[2] --;
                }
            }
            if(i != n - 1){
                cout << endl;
            }
        }
    }
    return 0;
}