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
	        if (!root) {
	            return result;
	        }
	
	        queue<TreeNode*> q;
	        q.push(root);
	
	        while (!q.empty()) {
	            int level_size = q.size();
	            for (int i = 0; i < level_size; ++i) {
	                TreeNode* current_node = q.front();
	                q.pop();
	
	                if (i == level_size - 1) {
	                    result.push_back(current_node->val);
	                }
	
	                if (current_node->left) {
	                    q.push(current_node->left);
	                }
	                if (current_node->right) {
	                    q.push(current_node->right);
	                }
	            }
	        }
	        return result;
	    }
	};