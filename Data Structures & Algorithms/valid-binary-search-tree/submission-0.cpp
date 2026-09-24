/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool trav(TreeNode * root,long long minval,long long maxval){
        if(!root)return true;
        if(root->val>=maxval||root->val<=minval)return false;
        return trav(root->left,minval,root->val)&&trav(root->right,root->val,maxval);
    }
    bool isValidBST(TreeNode *root) {
        // Your code her
        return trav(root,LLONG_MIN,LLONG_MAX);
    }
};
