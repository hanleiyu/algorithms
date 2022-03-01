#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root){
        if(root == nullptr){
            return -1;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);
        int cur = max(left, right) + 1;
        // size比idex大
        if(cur >= res.size()){
            res.push_back({});
        }
        res[cur].push_back(root->val);
        return cur;
    }
private:
    vector<vector<int>> res;
};