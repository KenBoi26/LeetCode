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
    vector<TreeNode*> al;
    vector<int> ans;

    bool root_to_tar(TreeNode* root, TreeNode* target) {
        if (root == nullptr)
            return false;

        if (root == target) {
            al.push_back(target);
            return true;
        }

        bool l = root_to_tar(root->left, target);
        bool r = root_to_tar(root->right, target);

        if (l)
            al.push_back(root);
        if (r)
            al.push_back(root);

        return l || r;
    }

    void dfs(TreeNode* root, TreeNode* border, int count) {
        if (root == nullptr || root == border)
            return;

        if (count == 0) {
            ans.push_back(root->val);
            return;
        }

        dfs(root->left, border, count - 1);
        dfs(root->right, border, count - 1);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        root_to_tar(root, target);

        TreeNode* temp = new TreeNode(-1);
        dfs(al[0], temp, k);

        for (int i = 1; i < al.size(); i++) {
            dfs(al[i], al[i - 1], k - i);
        }

        delete temp;
        return ans;
    }
};