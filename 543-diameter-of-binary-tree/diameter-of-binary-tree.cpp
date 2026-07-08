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

    int diameter = 0;

    int max_depth(TreeNode* root){
        if(!root) return 0;

        int left_depth = max_depth(root->left);
        int right_depth = max_depth(root->right);

        diameter = max(diameter, left_depth+right_depth);

        return 1+max(left_depth, right_depth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        max_depth(root);

        return diameter;
    }
};