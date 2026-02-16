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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        queue<TreeNode*> q;

        q.push(root);

        bool reversed=true;

        while(!q.empty()){
            vector<int> temp;
            int size = q.size();

            for(int i=0; i<size; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                temp.push_back(frontNode->val);
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }

            if(!reversed){
                reverse(temp.begin(), temp.end());
            }

            result.push_back(temp);
            
            reversed = !reversed;
        }


        return result;
    }
};