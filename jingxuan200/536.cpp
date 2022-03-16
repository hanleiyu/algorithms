#include <iostream>
#include <stack>
#include <string>
#include <cctype>
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
    TreeNode* str2tree(string s) {
        stack<TreeNode*> num;
        TreeNode* root = nullptr;
        if(s.length() > 0){
            for(int i = 0; i != s.length(); i ++){
                if(s[i] == '-' || s[i] == '('){
                    continue;
                }
                if(isdigit(s[i])){
                    int val = s[i] - '0';
                    int flag = 1;
                    if(i != 0 && s[i - 1] == '-'){
                        flag = -1;
                    }
                    i ++;
                    while(isdigit(s[i])){
                        val = val * 10 + (s[i] - '0');
                        i ++;
                    }
                    i --;
                    val = val * flag;
                    if(!num.empty()){
                        TreeNode* temp = new TreeNode(val);
                        TreeNode* top = num.top();
                        if(top->left == nullptr){
                            top->left = temp;
                        }else{
                            top->right = temp;
                        } 
                        num.push(temp);
                    }else{
                        root = new TreeNode(val);
                        num.push(root);
                    }                 
                }else if(s[i] == ')'){
                    num.pop();
                }
            }
        }
        return root;
    }
};