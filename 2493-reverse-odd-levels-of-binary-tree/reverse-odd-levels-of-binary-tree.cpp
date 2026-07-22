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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);

        bool odd = false;

        while(!q.empty()){
            int size = q.size();
            if(!odd){
                for(int i=0; i<size; i++){
                    TreeNode* node = q.front();
                    q.pop();
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }else{
                vector<TreeNode*> temp;
                for(int i=0; i<size; i++){
                    TreeNode* node = q.front();
                    q.pop();
                    temp.push_back(node);
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }

                int l = 0;
                int r = temp.size()-1;

                while(l<r){
                    int tempo = temp[l]->val;
                    temp[l]->val = temp[r]->val;
                    temp[r]->val = tempo;
                    l++;
                    r--;
                }
            }   

            odd = !odd;        
        }

        return root;
    }
};