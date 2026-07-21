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

    void helper(TreeNode* root, int &submax, int &count){
        if(!root){
            submax = INT_MIN;
            return;
        }

        int left, right;

        helper(root->left, left, count);

        helper(root->right, right, count);

        submax = max({root->val, left, right});

        if(root->val >= submax){
            count++;
        }


    }

    int countDominantNodes(TreeNode* root) {
        int count = 0;
        int submax;
        helper(root, submax, count);

        return count;
    }
};