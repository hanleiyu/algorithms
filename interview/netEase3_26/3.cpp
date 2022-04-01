#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> result;
    int sen = 0;
    string word;
    int flag = 0;
    while(cin >> word){
        if(result.empty()){
            result.push_back(word);
        }else if(flag == 1){
            result.push_back(word);
            sen ++;
            flag = 0; 
        }else if (result[sen].size() < (n - word.size() - 1)){
            result[sen].append(" ");
            result[sen].append(word);
        }else if (result[sen].size() < (n + m - word.size() - 1)){
            result[sen].append(" ");
            result[sen].append(word);
            flag = 1;
        }else if ((result[sen].size() == (n + m - word.size() - 1)) 
        && !(word.back() > 'A' && word.back() < 'Z' || word.back() < 'z' && word.back() > 'a')){
            result[sen].append(" ");
            result[sen].append(word);
            
            flag = 1;
        }else{
            result.push_back(word);
            sen ++;
        }
    }
    cout << sen + 1 << endl;
    for(int i = 0; i <= sen; i ++){
        cout << result[i];
        if(i != sen){
            cout << endl;
        }
    }
    return 0;
}

// 20 3
// I am coordinator ofg. Latin video games Federation. I'm born, member of the UWOOyan game Developers Association.

