#include <iostream>
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
    int ans;
    struct Node{
        int l, r, num;
    }
    Node bst(TreeNode* root){
        
    }


    int largestBSTSubtree(TreeNode* root) {
        bst(root);
        return ans;


        if(root == nullptr){
            return 0;
        }
        if(root != nullptr && root->left == nullptr && root->right == nullptr){
            return 1;
        }
        if(root->val > root->left->val && root->val < root->right->val){
            return largestBSTSubtree(root->left) + largestBSTSubtree(root->right) + 1;
        }else{
            return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
        }
    }
};