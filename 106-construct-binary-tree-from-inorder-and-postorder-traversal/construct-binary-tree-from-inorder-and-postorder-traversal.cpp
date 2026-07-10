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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        
        int index_of_root = -1;
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i]==postorder[postorder.size()-1]){
                index_of_root = i;
                break;
            }
        }

        vector<int> left_inorder(inorder.begin(), inorder.begin()+index_of_root);
        vector<int> left_postorder(postorder.begin(), postorder.begin()+index_of_root);

        vector<int> right_inorder(inorder.begin()+index_of_root+1, inorder.end());
        vector<int> right_postorder(postorder.begin()+index_of_root, postorder.end()-1);

        TreeNode* left = buildTree(left_inorder, left_postorder);
        TreeNode* right = buildTree(right_inorder, right_postorder);

        root->left = left;
        root->right = right;

        return root;
    }
};