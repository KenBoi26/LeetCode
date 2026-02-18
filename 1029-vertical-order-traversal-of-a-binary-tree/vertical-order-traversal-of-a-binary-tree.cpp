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

        if (root == nullptr) return result;

        map<int, map<int, multiset<int>>> mp;

        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int x = front.second.first;
            int y = front.second.second;

            mp[x][y].insert(node->val);

            if (node->left)
                q.push({node->left, {x - 1, y + 1}});

            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
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
