class Trie{
    struct Node{
        vector<Node*> links;
        int count;
        Node(): links(26,NULL), count(0){}
    };
    Node *root;
public:
    Trie(){root = new Node();}

    void addWord(string &word){
        Node *curr = root;
        for(char c:word){
            if(curr->links[c-'a']==NULL){
                curr->links[c-'a']=new Node();
            }
            curr = curr->links[c-'a'];
            curr->count++;
        }
    }

    int countPrefix(string &pref){
        Node *curr=root;
        for(char c:pref){
            if(curr->links[c-'a']==NULL) return 0;
            curr = curr->links[c-'a'];
        }
        return curr->count;
    }
};
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie ;
        for(auto word:words){
            trie.addWord(word);
        }
        return trie.countPrefix(pref);
    }
};