#include <iostream>
#include <stack>
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
    bool dfs(TreeNode* root, TreeNode* target, stack<TreeNode*>& res){
        if(root == target){
            return true;
        }
        if(root->right != nullptr){
            res.push(root->right);
            if(dfs(root->right, target, res) == true){
                return true;
            }
            res.pop();
        }
        if(root->left != nullptr){
            res.push(root->left);
            if(dfs(root->left, target, res) == true){
                return true;
            }
            res.pop();
        }
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> ps;
        ps.push(root);
        stack<TreeNode*> qs;
        qs.push(root);
        dfs(root, p, ps);
        dfs(root, q, qs);
        while(ps.size() != qs.size()){
            if(ps.size() > qs.size()){
                ps.pop();
            }else{
                qs.pop();
            }
        }
        while(ps.top() != qs.top()){
            ps.pop();
            qs.pop();
        }
        return ps.top();
    }
};