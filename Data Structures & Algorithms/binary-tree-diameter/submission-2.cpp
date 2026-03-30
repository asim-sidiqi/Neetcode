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

    pair<int,int> diameter(TreeNode* root){
        if(!root) return {0,0};

        pair<int,int> leftdiamHeight = diameter(root->left);
        pair<int,int> rightdiamHeight = diameter(root->right);

        int leftdiam = leftdiamHeight.first;
        int rightdiam = rightdiamHeight.first;
        int leftHeight = leftdiamHeight.second;
        int rightHeight = rightdiamHeight.second;

        pair<int,int> ans;
        int diam = leftHeight + rightHeight + 1;
        ans.first = max(diam,max(leftdiam,rightdiam));
        ans.second = max(leftHeight, rightHeight) + 1;

        return ans;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = diameter(root).first;
        return ans-1;
    }
};
