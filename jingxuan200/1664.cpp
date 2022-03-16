#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* p, stack<TreeNode*>& ps) {
        if(root == nullptr){
            return false;
        }
        if(root->val == p->val){
            ps.push(root);
            return true;
        }
        if(root->left == nullptr && root->right == nullptr){
            return false;
        }
        ps.push(root);
        
        if(dfs(root->left, p, ps) == true){
            return true;
        }else if(dfs(root->right, p, ps) == true){
            return true;
        }
        ps.pop();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> ps, qs;
        dfs(root, p, ps);
        dfs(root, q, qs);
        if(ps.empty() || qs.empty()){
            return nullptr;
        }
        while(ps.size() != qs.size()){
            if(ps.size() > qs.size()){
                ps.pop();
            }else{
                qs.pop();
            }
        }
        if(ps.empty() || qs.empty()){
            return nullptr;
        }
        while(ps.top()->val != qs.top()->val){
            ps.pop();
            qs.pop();
        }
        return ps.top();
    }
};