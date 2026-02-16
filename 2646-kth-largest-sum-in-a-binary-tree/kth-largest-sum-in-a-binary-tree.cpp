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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> s;

        if(!root) return -1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            long long sum = 0;
            long long size = q.size();

            for(int i=0; i<size; i++){
                TreeNode* frontNode = q.front();
                q.pop();

                sum += frontNode->val;

                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }

            s.push_back(sum);
        }

        sort(s.begin(), s.end());

        if(k <= s.size()){
            return s[s.size()-k];
        }

        return -1;

    }
};