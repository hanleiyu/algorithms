#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int thisL = 0;
        int nextL = 0;
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        nextL = 1;
        while(!q.empty()){
            thisL = nextL;
            nextL = 0;
            vector<int> node;
            while(thisL != 0){
                if(q.front()->left != nullptr){
                    q.push(q.front()->left);
                    nextL ++;
                }
                if(q.front()->right != nullptr){
                    q.push(q.front()->right);
                    nextL ++;
                }
                node.push_back(q.front()->val);
                q.pop();
                thisL --;
            }
            res.push_back(node);
        }
        return res;
    }
};