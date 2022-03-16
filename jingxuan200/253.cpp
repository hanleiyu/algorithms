#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:

    void pop_max_heap(priority_queue<vector<int>> heap){
        while(!heap.empty()){
            cout << heap.top()[0] << " " << heap.top()[1] << endl;
            heap.pop();
        }
    }

    void pop_min_heap(priority_queue<int, vector<int>, greater<int>> heap){
        while(!heap.empty()){
            cout << heap.top() << " " << heap.top() << endl;
            heap.pop();
        }
    }
    

    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int room = 0;
        for(int i = 0; i < intervals.size(); i ++){            
            if(min_heap.empty() || intervals[i][0] < min_heap.top()){
                min_heap.push(intervals[i][1]);
                room ++;
            }else{
                min_heap.pop();
                min_heap.push(intervals[i][1]);
            }
        }                
        return room;
    }
};

int main(){
    Solution s;
    vector<vector<int>> intervals = {{6,15}, {6,17}, {13,20}};
    cout << s.minMeetingRooms(intervals);
}