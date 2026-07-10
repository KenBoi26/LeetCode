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

    void dfs(TreeNode* root, int mn, int mx, int &ans){
        if(!root) return;

        mx = max(mx, root->val);
        mn = min(mn, root->val);

        ans = max(ans, mx-mn);

        dfs(root->left, mn, mx, ans);
        dfs(root->right, mn, mx, ans);


    }

    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, INT_MAX, INT_MIN, ans);
        return ans;        
    }
};