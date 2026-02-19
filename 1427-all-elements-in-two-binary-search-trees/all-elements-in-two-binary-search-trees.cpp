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

    void inorder(TreeNode* root, vector<int> &temp){
        if(!root) return;

        inorder(root->left, temp);
        temp.push_back(root->val);
        inorder(root->right, temp);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> one;
        inorder(root1,one);
        vector<int> two;
        inorder(root2, two);

        int n = one.size();
        int m = two.size();

        vector<int> result(n+m);
        int i=0,j=0,k=0;

        while(i<n && j<m){
            if(one[i] < two[j]){
                result[k++] = one[i++];
            }else{
                result[k++] = two[j++];
            }
        }

        while(i<n){
            result[k++] = one[i++];
        }

        while(j<m){
            result[k++] = two[j++];
        }

        return result;
    }
};