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
    void dfs(TreeNode* node, int level, vector<vector<int>>& ans) {
        if (node == NULL) return;

        // If we reach a new level, create a new vector
        if (level == ans.size()) {
            ans.push_back({});
        }

        // Add the current node's value to its corresponding level
        ans[level].push_back(node->val);

        // Traverse left and right subtrees with incremented level
        dfs(node->left, level + 1, ans);
        dfs(node->right, level + 1, ans);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);  // Start DFS from the root at level 0
        return ans;
    }
};