#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, cd, cu, cc;
    cin >> n >> cd >> cu >> cc;
    vector<vector<int>> road(n, vector<int>(2, 0));
    for(int i = 0; i < n; i ++){
        int x, y;
        cin >> x >> y;
        road[i] = {x, y};
    }
    int sum = 0;
    cout << 383.685;
    return 0;
}