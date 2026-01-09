class Solution {
public:
    // returns {depth, LCA node of deepest leaves}
    pair<int, TreeNode*> solve(TreeNode* root) {
        if (root == nullptr) {
            return {0, nullptr};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        if (left.first == right.first) {
            return {left.first + 1, root};
        } 
        else if (left.first > right.first) {
            return {left.first + 1, left.second};
        } 
        else {
            return {right.first + 1, right.second};
        }
    }

    // 🔴 Function name MUST match driver code
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).second;
    }
};
