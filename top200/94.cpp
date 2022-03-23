#include <iostream>
#include <vector>
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
    vector<int> res;

    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        if(root->left != nullptr){
            dfs(root->left);
        }
        res.push_back(root->val);
        if(root->right != nullptr){
            dfs(root->right);
        }
        return;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};