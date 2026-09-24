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
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        int cnt1 = height(root->left);
        if(cnt1 == -1) return -1;   // left subtree not balanced
        int cnt2 = height(root->right);
        if(cnt2 == -1) return -1;   // right subtree not balanced
        int cnt = abs(cnt2 - cnt1);
        if(cnt > 1) return -1;      // current node not balanced
        return 1 + max(cnt1, cnt2); // return height
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
