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

class Codec {
public:

    // Encodes a tree to a single string.
    void seri(TreeNode* root, string &s) {
        if (!root) {
            s += "N,";
            return;
        }
        s += to_string(root->val) + ",";
        seri(root->left, s);
        seri(root->right, s);
    }

    // Encodes a tree to a single string
    string serialize(TreeNode* root) {
        string s = "";
        seri(root, s);
        return s;
    }

    // helper: deserialize with index pointer
    TreeNode* btree(vector<string>& nodes, int &i) {
        if (i >= (int)nodes.size() || nodes[i] == "N") {
            i++;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(nodes[i++]));
        root->left = btree(nodes, i);
        root->right = btree(nodes, i);
        return root;
    }

    // Decodes your encoded data to tree
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp = "";
        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) nodes.push_back(temp);

        int i = 0;
        return btree(nodes, i);
    }
};
