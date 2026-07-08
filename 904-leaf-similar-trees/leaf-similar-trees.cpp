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

    void func(TreeNode* root, vector<int> &v){
        if(!root->left && !root->right) v.push_back(root->val);
        if(root->left) func(root->left, v);
        if(root->right) func(root->right, v);

    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> n,m;
        func(root1, n);
        func(root2, m);

        if(n.size() != m.size()) return false;

        for(int i=0; i<n.size(); i++){
            if(n[i] != m[i]) return false;
        }

        return true;
    }
};