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

    void dfs(TreeNode* root, int ls, int le, int rs, int re, vector<int>&nums){

        if(ls>le || rs>re) return;

        int max_left_index = -1, max_right_index = -1;
        int max_left = -1, max_right = -1;

        for(int i=ls; i<le; i++){
            if(nums[i] > max_left){
                max_left_index = i;
                max_left = nums[i];
            }
        }

        for(int i=rs; i<re; i++){
            if(nums[i] > max_right){
                max_right_index = i;
                max_right = nums[i];
            }
        }


        if(max_left_index != -1){
            TreeNode* node = new TreeNode(max_left);
            root->left = node;
            dfs(node, ls, max_left_index, max_left_index+1, le, nums);
        }

        if(max_right_index != -1){
            TreeNode* node = new TreeNode(max_right);
            root->right = node;
            dfs(node, rs, max_right_index, max_right_index+1, re, nums);
        }
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int max_index = -1;
        int maximum = -1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] > maximum){
                max_index = i;
                maximum = nums[i];
            }
        }

        TreeNode* root = new TreeNode(maximum);
        dfs(root, 0, max_index, max_index+1, nums.size(), nums);
        return root;
        
    }
};