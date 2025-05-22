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
    int cameras = 0;
    
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 1;  // Null nodes are considered covered

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == (-1) || right == (-1)) {
            // If any child needs to be covered, place a camera here
            cameras++;
            return 0; // This node has a camera
        }

        if (left == 0 || right == 0) {
            // If any child has a camera, this node is covered
            return 1;
        }

        // If children are covered but don’t have a camera, this node needs to be covered
        return -1;
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == -1) {
            // If root still needs to be covered, place one more camera
            cameras++;
        }
        return cameras;
    }
};
