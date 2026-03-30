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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;

        bool ans;
        bool curr;
        if(p->val == q->val) curr=true;
        else curr=false;

        bool leftStat = isSameTree(p->left,q->left);
        bool rightStat = isSameTree(p->right,q->right);

        if(curr && leftStat && rightStat) ans = true;
        else ans=false;

        return ans;
    }
};
