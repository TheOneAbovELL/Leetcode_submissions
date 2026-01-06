class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN;
        int level = 0;
        int result = 0;
        
        while (!q.empty()) {
            int size = q.size();
            int currentSum = 0;
            level++;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentSum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            if (currentSum > maxSum) {
                maxSum = currentSum;
                result = level;
            }
        }
        
        return result;
    }
};