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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;

        map<int, map<int, multiset<int>>> mp;

        queue<pair<TreeNode*,pair<int,int>>> q;

        if(!root) return result;

        q.push({root, {0,0}});

        while(!q.empty()){
            auto element = q.front();
            q.pop();

            TreeNode* node = element.first;
            int x = element.second.first;
            int y = element.second.second;

            mp[x][y].insert(node->val);

            if(node->left) q.push({node->left, {x-1, y+1}});
            if(node->right) q.push({node->right, {x+1, y+1}});
        }

        for (auto &i : mp) {
            vector<int> temp;
            for (auto &j : i.second) {
                for (int val : j.second) {
                    temp.push_back(val);
                }
            }

            result.push_back(temp);
        }

        return result;

    }
};