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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        function<void(TreeNode*)> inorder=[&](TreeNode* node){
            if(!node) return;
            inorder(node->left);
            vals.push_back(node->val);
            inorder(node->right);
        };
        inorder(root);
        function<TreeNode*(int,int)> build=[&](int l,int r)->TreeNode*{
            if(l>r) return nullptr;
            int m=(l+r)/2;
            TreeNode* node=new TreeNode(vals[m]);
            node->left=build(l,m-1);
            node->right=build(m+1,r);
            return node;
        };
        return build(0,vals.size()-1);
    }
};