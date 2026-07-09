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

    int helper(TreeNode* root, long long sum, int targetSum){
        if(!root) return 0;

        sum += root->val;

        int count = 0;
        if(sum == targetSum) count = 1;

        count += helper(root->left, sum, targetSum);
        count += helper(root->right, sum, targetSum);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        return helper(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
        
    }
};