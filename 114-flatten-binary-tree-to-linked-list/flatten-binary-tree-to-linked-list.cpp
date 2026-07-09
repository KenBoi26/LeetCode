class Solution {
public:

    TreeNode* prevNode = nullptr;

    void flatten(TreeNode* root) {

        if(!root) return;

        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prevNode;
        root->left = nullptr;
        prevNode = root;
        
        
    }
};