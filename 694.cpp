#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        set<set<vector<int>>> islands;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i ++){
            for(int j = 0; j < cols; j ++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    islands.insert(findIsland(grid, visited, i, j));
                }
            }
        }
        return islands.size();
    }

    set<vector<int>> findIsland(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j){
        queue<vector<int>> index;
        set<vector<int>> island;
        int direction[4][2] = { {1, 0}, {0, 1}, {-1, 0},  {0, -1}};
        visited[i][j] = 1;
        index.push({i, j});
        island.insert({0,0});

        while(!index.empty()){
            vector<int> position = index.front();
            index.pop();
            for(int k = 0; k < size(direction); k ++){
                int r = position[0] + direction[k][0];
                int c = position[1] + direction[k][1];

                if(r>=0 && r < grid.size() 
                && c>=0 && c < grid[0].size() 
                && grid[r][c] == 1 && visited[r][c] == 0){
                    visited[r][c] = 1;
                    index.push({r, c});
                    island.insert({r - i, c - j});
                }
            }
        }

        return island;
    }
};