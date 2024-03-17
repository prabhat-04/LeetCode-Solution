class Trie {
 struct TrieNode{
    TrieNode *child[26];
    bool isLeaf = false;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
 } ;
 TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *ptr = root;
        for(char ch:word ){
            if(!ptr->child[ch-'a']){
                ptr->child[ch-'a'] = new TrieNode();
            }
            ptr = ptr ->child[ch-'a'];
        }
        ptr->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode * ptr = root;
        for(char ch:word){
            if(!ptr->child[ch-'a']) return false;
            ptr = ptr->child[ch-'a'];
        }
        return ptr->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode *ptr = root;
        for(char ch:prefix){
            if(!ptr->child[ch-'a']) return false;
            ptr = ptr->child[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */