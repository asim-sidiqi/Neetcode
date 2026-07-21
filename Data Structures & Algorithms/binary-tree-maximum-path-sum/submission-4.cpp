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
    int maxi = INT_MIN;
    int solve(TreeNode* root){
        if(!root) return INT_MIN;

        int f = root->val;
        int l = max(0,solve(root->left));
        int r = max(0,solve(root->right));

        int peak = l + f + r;
        maxi = max(maxi,peak);
    
        return max(l,r)+f;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root->left && !root->right) return root->val;
        solve(root);
        return maxi;
    }
};
