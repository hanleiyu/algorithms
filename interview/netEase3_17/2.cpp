#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

class Solution{
public:
    int size;
    int move;
    vector<string> chese;
    vector<vector<int>> position;
    set<vector<int>> thisp;
    set<vector<int>> prep;
    Solution(int size, int move, vector<string> chese, vector<vector<int>> position):
    size(size), move(move), chese(chese), position(position){}
    void Process(){
        for(int i = 0; i < move; i ++){           
            int x = position[i][0];
            int y = position[i][1];
            char me = 'w';
            char target = 'b';
            if(i % 2 == 1){
                me = 'b';
                target = 'w';
            }
            chese[x][y] = me;
            int target_p;
            //上
            for(int target_p = 0; target_p < x; target_p ++){
                if(chese[target_p][y] == target){
                    break;
                }
            }
            if(target_p != x){
                change(target_p, y, x, y);
            }
            //下
            for(int target_p = size - 1; target_p > x; target_p --){
                if(chese[target_p][y] == target){
                    break;
                }
            }
            if(target_p != x){
                change(x, y, target_p, y);
            }
            //左
            for(int target_p = 0; target_p < y; target_p ++){
                if(chese[x][target_p] == target){
                    break;
                }
            }
            if(target_p != y){
                change(x, target_p, x, y);
            }
            //右
            for(int target_p = size - 1; target_p > y; target_p --){
                if(chese[x][target_p] == target){
                    break;
                }
            }
            if(target_p != y){
                change(x, y, x, target_p);
            }
            //左上
            int target_x = x;
            int target_y = y;
            while(target_x > 0 && target_y > 0){
                target_x --;
                target_y --;
            }
            while(chese[target_x][target_y] != target && target_x < x && target_y <y){
                target_x ++;
                target_y ++;
            }
            if(target_x != x){
                change(target_x, target_y, x, y);
            }
            //右上
            target_x = x;
            target_y = y;
            while(target_x > 0 && target_y < size){
                target_x --;
                target_y ++;
            }
            while(chese[target_x][target_y] != target && target_x < x && target_y > y){
                target_x ++;
                target_y --;
            }
            if(target_x != x){
                change(target_x, target_y, x, y);
            }
            //左下
            target_x = x;
            target_y = y;
            while(target_x < size && target_y > 0){
                target_x ++;
                target_y --;
            }
            while(chese[target_x][target_y] != target && target_x > x && target_y < y){
                target_x --;
                target_y ++;
            }
            if(target_x != x){
                change(target_x, target_y, x, y);
            }
            //右下
            target_x = x;
            target_y = y;
            while(target_x < size && target_y < size){
                target_x ++;
                target_y ++;
            }
            while(chese[target_x][target_y] != target && target_x > x && target_y > y){
                target_x --;
                target_y --;
            }
            if(target_x != x){
                change(target_x, target_y, x, y);
            }
        }
        for(int i = 0; i < size; i ++){
            cout << chese[i] << endl;
        }
        cout << "END" << endl;
        return;
    }

    void change(int startx, int starty, int endx, int endy){
        int tempx = 0;
        int tempy = 0;
        if(startx == endx){
            tempy = 1;
        }else if (starty == endy){
            tempx = 1;
        }else{
            tempx = 1;
            tempy = 1;
            if(endx < startx){
                tempx = -1;
            }
            if(endy < starty){
                tempy = -1;
            }
        }
        
        for(int i = startx + tempx, j = starty + tempy; i != endx, j != endy; i += tempx, j += tempy){
            if(chese[i][j] == 'w' && prep.find({i, j}) == prep.end()){
                chese[i][j] = 'b';
                thisp.insert({i, j});
            }else if(chese[i][j] == 'b' && prep.find({i, j}) == prep.end()){
                chese[i][j] = 'w';
                thisp.insert({i, j});
            }
        }
        
        prep = thisp;
        thisp.clear();
    }
};

void read(int size, int move, vector<string>& chese, vector<vector<int>>& position){
    for(int i = 0; i < size; i ++){
        string x;
        cin >> x;
        chese.push_back(x);
    }
    for(int i = 0; i < move; i ++){
        int x;
        int y;
        scanf("%d",&x);
        scanf("%d",&y);
        position.push_back({x, y});
    }
    return;
}

int main(){
    int n,ans = 0;
    cin >> n;
    vector<int> sizes;
    vector<int> moves;
    vector<vector<string>> cheses;
    vector<vector<vector<int>>> positions;
    for(int i = 0; i < n; i++){
        int size = 0;
        int move = 0;
        scanf("%d",&size);
        scanf("%d",&move);
        sizes.push_back(size);
        moves.push_back(move);
        vector<string> chese;
        vector<vector<int>> position;
        read(size, move, chese, position);
        cheses.push_back(chese);
        positions.push_back(position);
    }
    for(int i = 0; i < n; i ++){
        Solution solution(sizes[i], moves[i], cheses[i], positions[i]);
        solution.Process();
    }
    return 0;
}

// 2
// 6 4
// ------
// ---b--
// -wwwb-
// -bbw--
// -ww---
// -ww---
// 1 2
// 0 2
// 2 0
// 2 5
// 6 4
// ------
// --b---
// --wbb-
// --www-
// --b-b-
// --w---
// 1 4
// 1 1
// 5 4
// 0 2


// --b---
// --bb--
// wbwbwb
// -www--
// -wb---
// -ww---
// END
// --b---
// -bw-w-
// --wbw-
// --bwb-
// --w-w-
// --w-w-
// END