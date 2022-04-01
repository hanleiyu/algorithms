#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int m;
    cin >> m;
    vector<vector<int>> cards;
    cards.assign(10, {0});
    while(m != 0){
        int n; 
        cin >> n;
        vector<int> nums;
        vector<char> words;
        for(int i = 0; i < n; i ++){
            int num;
            cin >> num;
            nums.push_back(num);
        }
        for(int i = 0; i < n; i ++){
            char num;
            cin >> num;
            words.push_back(num - 'A' + 1);
        }
        map<int, int> single;
        for(int i = 0; i < n; i ++){
            if(single.find(nums[i]) == single.end()){
                single.insert({nums[i], 1});
            }else{
                single[nums[i]] ++;
            }
        }
        if(n == 1){
            cout << 1;
        }else if (n == 2){
            if(nums[0] == nums[1]){
                cout << 2;
            }else{
                cout << 1;
            }
        }else if (n == 3){
            int size = single.size();      
            if(size == 3){
                cout << 1;
            }else if (size == 2){
                cout << 2;
            }else{
                cout << 6;
            }
        }else if (n == 4){
            int max_num = 1;
            for(auto it = single.begin(); it != single.end(); it ++){
                if(it->second > max_num){
                    max_num = it->second;
                }
            }
            if(max_num == 4){
                cout << 150;
            }else if (max_num == 3){
                cout << 6;
            }else if (max_num == 2){
                if(single.size() == 2){
                    cout << 4;
                }else{
                    cout << 2;
                }
            }else{
                cout << 1;
            }
        }else{
            int size = single.size();
            if(size == 1){
                cout << 15000;
            }else{
                int word = words[0];
                for(int i = 1; i < n; i ++){
                    if(words[i] != word){
                        word = -1;
                        break;
                    }
                }
                if(word != -1){
                    if(size != 5){
                        cout << 300;
                    }else{
                        int small = single.begin()->first;
                        int biggest = 1;
                        for(auto it = single.begin(); it != single.end(); it ++){
                            if(it->first > biggest){
                                biggest = it->first;
                            }
                        }
                        if((biggest - small) == 4){
                            cout << 8000;
                        }else{
                            cout << 300;
                        }
                    }
                }else{
                    int max_num = 1;
                    for(auto it = single.begin(); it != single.end(); it ++){
                        if(it->second > max_num){
                            max_num = it->second;
                        }
                    }
                    if(max_num == 4){
                        cout << 150;
                    }else if(max_num == 3){
                        if(size == 2){
                            cout << 40;
                        }else{
                            cout << 6;
                        }
                    }else if(max_num == 2){
                        if(size == 3){
                            cout << 4;
                        }else if(size == 4){
                            cout << 2;
                        }
                    }else{
                        int small = single.begin()->first;
                        int biggest = 1;
                        for(auto it = single.begin(); it != single.end(); it ++){
                            if(it->first > biggest){
                                biggest = it->first;
                            }
                        }
                        if((biggest - small) == 4){
                            cout << 20;
                        }else{
                            cout << 1;
                        }
                    }
                }
            }
        }
        m --;
        if(m != 0){
            cout << endl;
        }
    }
    return 0;
}