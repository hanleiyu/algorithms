#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x; scanf("%d",&x);
            ans += x;
        }
    }
    cout << ans << endl;
    return 0;
}

// 2
// 1 10 1 1
// 4
// 0++++E++++
// 4 4 2 2
// 4 4
// 0++1
// EWW+
// +WW+
// +E++

// -1
// 8