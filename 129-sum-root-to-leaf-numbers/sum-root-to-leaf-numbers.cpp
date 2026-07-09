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

    void helper(TreeNode* root, int num, vector<int> &numbers){
        if(!root) return;

        num = num*10 + root->val;

        if(!root->left && !root->right){
            numbers.push_back(num);
        }else{
            helper(root->left, num, numbers);
            helper(root->right, num, numbers);
        }


    }

    int sumNumbers(TreeNode* root) {
        vector<int> numbers;
        helper(root, 0, numbers);

        int sum = 0;

        for(auto i:numbers){
            sum += i;
        }

        return sum;
    }
};