class WordDictionary {
    struct TrieNode{
        TrieNode *child[26];
        bool isLeaf = false;
        TrieNode(){
            for(int i=0;i<26;i++){
                child[i]=NULL;
        }
    }
 };
TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *ptr = root;
        for(char ch:word ){
            if(!ptr->child[ch-'a']){
                ptr->child[ch-'a'] = new TrieNode();
            }
            ptr = ptr ->child[ch-'a'];
        }
        ptr->isLeaf = true;        
    }

    bool help(int i,string word,TrieNode *ptr){
        if(ptr==NULL) return false;
        if(i==word.size()){
            return ptr->isLeaf;
        }
        if(word[i]!='.'){
            if(!ptr->child[word[i]-'a']) return false;
            return help(i+1,word,ptr->child[word[i]-'a']);
        } 
        else{
            for(int j=0;j<26;j++){
                if(help(i+1,word,ptr->child[j])) return true;
            }
        }
        return false;
    }
    
    bool search(string word) {
        return help(0,word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */