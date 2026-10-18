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
    bool check(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (!node) return true;
        if ((minNode && node->val <= minNode->val) || 
            (maxNode && node->val >= maxNode->val)) {
            return false;
        }
        return check(node->left, minNode, node) && check(node->right, node, maxNode);
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, nullptr, nullptr);
    }
};