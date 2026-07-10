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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if(preorder.empty()) return nullptr;
        if(preorder.size()==1) return new TreeNode(preorder[0]);

        TreeNode* root = new TreeNode(preorder[0]);

        int split = 0;

        while(preorder[1] != postorder[split]) split++;

        vector<int> left_preorder(preorder.begin()+1, preorder.begin()+split+2);
        vector<int> left_postorder(postorder.begin(), postorder.begin()+split+1);

        vector<int> right_preorder(preorder.begin()+split+2, preorder.end());
        vector<int> right_postorder(postorder.begin()+split+1, postorder.end()-1);

        TreeNode* left = constructFromPrePost(left_preorder, left_postorder);
        TreeNode* right = constructFromPrePost(right_preorder, right_postorder);

        root->left = left;
        root->right = right;

        return root;
    }
};