#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(start == destination){
            return true;
        }
        queue<vector<int>> Q;
        set<vector<int>> visited;
        Q.push(start);
        visited.insert(start);
        while(!Q.empty()){
            int cur_len = Q.size();
            while(cur_len != 0){
                vector<int> s = Q.front();
                Q.pop(); 
                for(auto d : vector<vector<int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}){
                    vector<int> e = {0, 0};
                    e[0] = s[0] + d[0];
                    e[1] = s[1] + d[1];
                    if(e[0] < 0 || e[0] == maze.size() || e[1] < 0 || e[1] == maze[0].size()){
                        continue; 
                    }
                    while(e[0] >= 0 && e[1] >= 0 && e[0] < maze.size() && e[1] < maze[0].size() && maze[e[0]][e[1]] != 1){
                        e[0] += d[0];
                        e[1] += d[1];
                    }
                    e[0] -= d[0];
                    e[1] -= d[1];
                    if(visited.find(e) == visited.end()){
                        if(e == destination){
                            return true;
                        }
                        visited.insert(e);
                        Q.push(e);
                    }
                }
                cur_len --;
            }

        }
        return false;
    }
};