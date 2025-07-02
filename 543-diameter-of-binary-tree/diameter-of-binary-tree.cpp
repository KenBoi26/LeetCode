class Solution {
public:
    int most(TreeNode* root, int &ans){
        if(root == NULL){
            return 0;
        }
        int left = most(root->left, ans);
        int right = most(root->right, ans);
        ans = max(left + right, ans);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        most(root, ans);
        return ans;
    }
};