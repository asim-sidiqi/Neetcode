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
    int minValBST(TreeNode* root){
        if(!root) return -1;
        
        TreeNode* temp = root;
        while(temp->left){
            temp = temp->left;
        }

        return temp->val;
    }

    int maxValBST(TreeNode* root){
        if(!root) return -1;

        TreeNode* temp = root;
        while(temp->right){
            temp = temp->right;
        }

        return temp->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }

        else{
            //0-child
            if(!root->right && !root->left){
                delete root;
                return NULL;
            }

            //left-child
            if(!root->right && root->left){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            //right-child
            if(root->right && !root->left){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            //2-child
            if(root->right && root->left){
                int maxi = maxValBST(root->left);
                root->val = maxi;

                root->left = deleteNode(root->left,maxi);
                return root;
            }
        }

        return root;
    }
};