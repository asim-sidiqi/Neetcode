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
    int height(TreeNode* root){
        if(!root) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
    }

    pair<int,bool> isBalancedFaster(TreeNode* root){
        if(!root) return {0,true};

        pair<int,bool> leftBalanced = isBalancedFaster(root->left);
        pair<int,bool> rightBalanced = isBalancedFaster(root->right);

        bool balanced = abs(leftBalanced.first-rightBalanced.first)<=1;

        pair<int,bool> ans;
        ans.first = max(leftBalanced.first,rightBalanced.first)+1;

        if(leftBalanced.second && rightBalanced.second && balanced){
            ans.second = true;
        }
        else{
            ans.second = false;
        }

        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedFaster(root).second;
    }
};
