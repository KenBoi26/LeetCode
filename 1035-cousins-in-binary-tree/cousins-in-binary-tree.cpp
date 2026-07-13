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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        
        bool flag = true;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();

                if((node->left && node->right) && ((node->left->val == x && node->right->val == y) || (node->left->val == y && node->right->val == x))) return false;
                q.pop();

                temp.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            bool found1 = (find(temp.begin(), temp.end(), x) != temp.end());
            bool found2 = (find(temp.begin(), temp.end(), y) != temp.end());

            if(found1||found2){
                return found1 && found2;
            }
        }

        return false;
    }
};