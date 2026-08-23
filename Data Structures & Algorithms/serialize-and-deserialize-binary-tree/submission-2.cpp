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


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();

            if(!t){
                s+="#,";
                continue;
            }

            s+=to_string(t->val);
            s += ",";

            q.push(t->left);
            q.push(t->right);
        }

        return s;
    }

    // Decodes your encoded data to tree.
    //1,2,3,#,#,4,5,#,#,#,#,
    TreeNode* deserialize(string data) {
        if (data == "#") return NULL;

        vector<string> tokens;
        string temp="";
        for(auto c:data){
            if(c==','){
                tokens.push_back(temp);
                temp="";
            }
            else temp+=c;
        }

        int n = tokens.size();
        int i = 0;

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(tokens[i]));
        i++;
        q.push(root);
        while(!q.empty() && i<n){
            TreeNode* t = q.front();
            q.pop();

            if(i<n && tokens[i]!="#"){
                t->left = new TreeNode(stoi(tokens[i]));
                q.push(t->left);
            }

            i++;

            if(i<n && tokens[i]!="#"){
                t->right = new TreeNode(stoi(tokens[i]));
                q.push(t->right);
            }

            i++;
        }

        return root;
    }
};
