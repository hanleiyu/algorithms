#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int dis = wordsDict.size();
        int pos1 = -1;
        int pos2 = -1;
        for(int i = 0; i < wordsDict.size(); i ++){
            if(wordsDict[i].compare(word1) == 0 && word1 == word2){
                if(pos1 == -1 || pos1 < pos2){
                    pos1 = i;
                }else{
                    pos2 = i;
                }
            }else if(wordsDict[i].compare(word1) == 0){
                pos1 = i;
            }else if (wordsDict[i].compare(word2) == 0){
                pos2 = i;
            }
            if(pos1 != -1 && pos2 != -1){
                if(abs(pos1 - pos2) < dis){
                    dis = abs(pos1 - pos2);
                }
            }
        }
        return dis;
    }
};