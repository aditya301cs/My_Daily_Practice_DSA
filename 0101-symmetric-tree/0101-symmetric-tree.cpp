/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
bool checkSymmetry(TreeNode* leftSubtree, TreeNode* rightSubtree) {
    if (leftSubtree == nullptr && rightSubtree == nullptr) {
        return true;
    }

    if (leftSubtree == nullptr || rightSubtree == nullptr) {
        return false;
    }

    if (leftSubtree->val != rightSubtree->val) {
        return false;
    }

    return checkSymmetry(leftSubtree->left, rightSubtree->right) &&
           checkSymmetry(leftSubtree->right, rightSubtree->left);
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) { 
    return checkSymmetry(root, root); 
    }
};
