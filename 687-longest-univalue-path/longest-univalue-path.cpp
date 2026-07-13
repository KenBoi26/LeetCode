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

    int maxi = 0;

    int helper(TreeNode* root){
        if(!root) return 0;

        int left_length = helper(root->left);
        int right_length = helper(root->right);

        int l_path = 0;
        int r_path = 0;

        if(root->left && root->left->val == root->val) l_path = left_length + 1;
        if(root->right && root->right->val == root->val) r_path = right_length + 1;

        maxi = max(maxi, l_path + r_path);

        return max(l_path, r_path);
    }

    int longestUnivaluePath(TreeNode* root) {
        if(!root) return maxi;
        
        helper(root);

        return maxi;

    }
};