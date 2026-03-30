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

        return max(leftHeight,rightHeight) + 1;
    }

    int diameter(TreeNode* root){
        if(!root) return 0;

        int leftdiam = diameter(root->left);
        int rightdiam = diameter(root->right);
        int diam = height(root->left)+height(root->right)+1;

        return max(diam, max(leftdiam,rightdiam));
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = diameter(root);
        return ans-1;
    }
};
