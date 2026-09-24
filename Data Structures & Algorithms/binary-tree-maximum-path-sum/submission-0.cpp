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
     int sum;
    int maxsum(TreeNode* root){
        if(root==NULL)return 0;
        int lh=max(0,maxsum(root->left));
        int rh=max(0,maxsum(root->right));
        sum=max(sum,root->val+lh+rh);
        return root->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        sum=INT_MIN;
        maxsum(root);
        return sum;
    }
};
