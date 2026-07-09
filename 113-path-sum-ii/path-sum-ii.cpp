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

    bool hasPathSum(TreeNode* root, int targetSum, int sum=0){
        if(!root) return false;
        if(!root->left && !root->right && sum+root->val == targetSum) return true;
        
        return hasPathSum(root->left, targetSum, sum+root->val) || hasPathSum(root->right, targetSum, sum+root->val);

    }

    void get_path(TreeNode* root, int targetSum, vector<int> path, int sum, vector<vector<int>> &result){
        if(!root) return;
        path.push_back(root->val);
        if(!root->left && !root->right && sum+root->val == targetSum){
            result.push_back(path);
        }
        
        get_path(root->left, targetSum, path, sum+root->val, result);

        get_path(root->right, targetSum, path, sum+root->val, result);

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        if(!root) return {};
        if(root->val == targetSum && !root->left && !root->right) return {{root->val}};
        if(hasPathSum(root, targetSum)){
            get_path(root, targetSum, {}, 0, result);
        }
        

        return result;
    }
};