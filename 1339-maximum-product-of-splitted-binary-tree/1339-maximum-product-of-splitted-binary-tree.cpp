class Solution {
public:
    int maxProduct(TreeNode* root) {
        long long total=0,res=0;
        function<void(TreeNode*)> sum=[&](TreeNode* node){
            if(!node)return;
            total+=node->val;
            sum(node->left);
            sum(node->right);
        };
        sum(root);
        function<long long(TreeNode*)> dfs=[&](TreeNode* node)->long long{
            if(!node)return 0;
            long long s=node->val+dfs(node->left)+dfs(node->right);
            res=max(res,s*(total-s));
            return s;
        };
        dfs(root);
        return res%1000000007;
    }
};