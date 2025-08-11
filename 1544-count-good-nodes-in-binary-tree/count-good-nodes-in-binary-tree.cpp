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

    int dfs(TreeNode* node, int maximum){
        if(!node) return 0;

        int result = (node->val >= maximum) ? 1 : 0;
        maximum = max(node->val, maximum);

        result += dfs(node->left, maximum);
        result += dfs(node->right, maximum);

        return result;
    }

    int goodNodes(TreeNode* root) {
        
        return dfs(root, root->val);
        
    }
};
