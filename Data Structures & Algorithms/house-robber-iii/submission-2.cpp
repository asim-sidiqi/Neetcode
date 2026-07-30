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
private:
    int solve(TreeNode* root, unordered_map<TreeNode*,int>& dp){
        if(!root) return 0;

        if(dp[root]) return dp[root]; 

        int ll=0,rr=0,lr=0,rl=0;
        int f = root->val;
        int l = solve(root->left, dp);
        int r = solve(root->right, dp);
        if(root->left) ll = solve(root->left->left, dp);
        if(root->right) rr = solve(root->right->right, dp);
        if(root->left) lr = solve(root->left->right, dp);
        if(root->right) rl = solve(root->right->left, dp);

        int op1 = f + ll + lr + rl + rr;
        int op2 = l+r;

        return dp[root] = max(op1,op2);
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return solve(root,dp);
    }
};