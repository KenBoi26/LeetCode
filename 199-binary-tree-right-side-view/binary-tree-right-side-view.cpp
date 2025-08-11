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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;

        deque<TreeNode*> q;
        q.push_back(root);


        while(!q.empty()){
            vector<int> temp;
            int length = q.size();
            for(int i=0; i<length; i++){
                TreeNode* node = q.front();
                q.pop_front();
                temp.push_back(node->val);

                if(node->left) q.push_back(node->left);
                if(node->right) q.push_back(node->right);

            }
            result.push_back(temp[length-1]);
        }


        return result;
    }
};
