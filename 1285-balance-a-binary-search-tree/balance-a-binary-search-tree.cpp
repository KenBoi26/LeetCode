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
    vector<int> order;
    void inor(TreeNode* node){
        if(node == NULL) return;
        inor(node->left);
        order.push_back(node->val);
        inor(node->right);
    }

    TreeNode* construct(int left, int right){
        if(left > right) return NULL;
        int mid = (left+right)/2;
        TreeNode* node = new TreeNode(order[mid]);
        node->left = construct(left, mid-1);
        node->right = construct(mid+1, right);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inor(root);
        return construct(0, order.size()-1);
    }
};