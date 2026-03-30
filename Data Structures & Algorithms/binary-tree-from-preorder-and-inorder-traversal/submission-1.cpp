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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preOrderIndex, int inorderStart, int inorderEnd, int n, unordered_map<int,int>& m){
        if(preOrderIndex>=n || inorderStart>inorderEnd) return NULL;

        int rootVal = preorder[preOrderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int pos = m[rootVal];
        root->left = solve(preorder, inorder, preOrderIndex, inorderStart, pos-1, n,m);
        root->right = solve(preorder, inorder, preOrderIndex, pos+1, inorderEnd, n, m);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preOrderIndex = 0;
        int inorderStart = 0, inorderEnd = n-1;
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            m[inorder[i]] = i;
        }

        return solve(preorder, inorder, preOrderIndex, inorderStart, inorderEnd, n, m);
    }
};
