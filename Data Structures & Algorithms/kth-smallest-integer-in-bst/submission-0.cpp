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
    void arr(TreeNode*root,vector<int>&x){
        if(!root)return;
        arr(root->left,x);
        x.push_back(root->val);
        arr(root->right,x);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return -1;
        vector<int>x;
        arr(root,x);
        if(k>x.size())return -1;
        return x[k-1];

    }
};
