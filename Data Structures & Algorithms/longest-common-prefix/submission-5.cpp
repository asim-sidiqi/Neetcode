class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char ch){
        this->data = ch;
        for(int i =0; i<26; i++){
            this->children[i]=NULL;
        }
        this->isTerminal=false;
        this->childCount=0;
    }
};

class Trie{
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }

        char temp = word[0];
        int index = temp-'a';
        TrieNode* child;

        if(root->children[index]==NULL){
            child = new TrieNode(temp);
            root->childCount++;
            root->children[index] = child;
        }else{
            child = root->children[index];
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    string lcp(string first){
        TrieNode* temp = root;
        string ans = "";
        for(int i=0; i<first.size(); i++){
            int index = first[i]-'a';
            if(temp->childCount==1 && temp->children[index] != NULL){
                ans+=first[i];
                temp = temp->children[index];
            }
            else break;

            if(temp->isTerminal) break;
        }

        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        for(auto i:strs){
            if(i=="") return "";
            t.insertWord(i);
        }

        return t.lcp(strs[0]);
    }
};