class Node{
public:
    Node *links[26]={};

    bool contains(char c){return links[c-'a']!=NULL;}

    void put(char c,Node *node){links[c-'a']=node;}

    Node *next(char c){return links[c-'a'];}
};

class Trie{
public:
    Node *root;
    Trie(){root = new Node();}
    void insert(string &word){
        Node *node = root;
        for(char c:word){
            if(!node->contains(c)){
                node->put(c,new Node());
            }
            node = node->next(c);
        }
    }
    bool startsWith(string &prefix){
        Node *node = root;
        for(char c:prefix){
            if(node->contains(c)){
                node = node->next(c);
            }
            else
                return false;
        }
        return true;
    }
};
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count=0;
        for(int i=0;i<n;i++){
            Trie prefixTrie, suffixTrie;
            prefixTrie.insert(words[i]);
            string str = words[i];
            reverse(str.begin(),str.end());
            suffixTrie.insert(str);
            for(int j=0;j<i;j++){
                if(words[j].size()>words[i].size()) continue;
                string rev = words[j];
                reverse(rev.begin(),rev.end());
                if(prefixTrie.startsWith(words[j]) && suffixTrie.startsWith(rev))
                    count++;
            }
        }
        return count;
    }
};