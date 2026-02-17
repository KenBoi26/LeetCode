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
    TreeNode* subTree(TreeNode* root, vector<int> &nums, int l, int r){
        if(l > r) return root;
        int mid = (l+r)/2;
        TreeNode* temp = new TreeNode(nums[mid]);
        root = temp;
        
        temp->left = subTree(root->left, nums, l, mid-1);
        temp->right = subTree(root->right, nums, mid+1, r);

        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        root = subTree(root, nums, 0, nums.size()-1);

        return root;
    }
};