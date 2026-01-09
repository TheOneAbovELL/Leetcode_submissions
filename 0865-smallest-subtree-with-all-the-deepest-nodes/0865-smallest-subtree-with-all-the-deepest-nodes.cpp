class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        function<pair<int,TreeNode*>(TreeNode*,int)>dfs=[&](TreeNode* node,int d)->pair<int,TreeNode*>{
            if(!node)return{d,nullptr};
            auto l=dfs(node->left,d+1),r=dfs(node->right,d+1);
            if(l.first==r.first)return{l.first,node};
            return l.first>r.first?l:r;
        };
        return dfs(root,0).second;
    }
};