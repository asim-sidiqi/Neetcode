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
    bool sameTree(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;

        bool curr = p->val == q->val;

        bool leftStat = sameTree(p->left, q->left);
        bool rightStat = sameTree(p->right, q->right);

        if(curr && leftStat && rightStat) return true;
        else return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false; 

        if(sameTree(root,subRoot)) return true;
        else{
            return(isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
        }                                                        
    }
};
