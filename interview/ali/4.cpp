#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    string target;
    cin >> target;
    int n;
    cin >> n;
    vector<string> value(n, "");
    vector<string> result;
    map<int, int> node;
    for(int i = 0; i < n; i ++){
        string s;
        int me;
        int father;
        cin >> s >> me >> father;
        value[me] = s;
        node.insert(pair(me, father));
    }

    for(int i = 0; i < n; i ++){
        if(value[i] == target){
            stack<string> fathers;
            string path;
            int f = node[i];
            while(f != -1){
                fathers.push(value[f]);
                f = node[f];
            }
            while(!fathers.empty()){
                path.append(fathers.top());
                fathers.pop();
                path.append("/");                
            }
            path.append(target);
            result.push_back(path);
        }
    }

    sort(result.begin(), result.end());
    int size = result.size();
    for(int i = 0; i < size; i ++){
        cout << result[i];
        if(i != size - 1){
            cout << endl;
        }
    }
    return 0;
}