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
    int closestValue(TreeNode* root, double target) {
        if(root == nullptr) {
            return -1;
        }
        int closest = root -> val;
        while(root != nullptr) {
            closest = abs(root -> val - target) < abs(closest - target) ? root -> val : closest;
            if(target < root -> val) {
                root = root -> left;
            } else {
                root = root -> right;
            }
        }
        return closest;

    }
};