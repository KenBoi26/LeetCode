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

    void compute(vector<vector<int>>&ans, vector<int> & path, TreeNode* node, int sum, int target){
        if(node == NULL) return;

        path.push_back(node->val);
        sum+=node->val;

        if(target == sum & node->left == NULL && node->right == NULL){
            ans.push_back(path);
        }
        compute(ans,path,node->left,sum,target);

        compute(ans, path, node->right, sum, target);

        path.pop_back();
        sum -= node->val;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        compute(ans, path, root, 0, targetSum);
        return ans;
    }
};