struct TrieNode{
    TrieNode *next[26]={};
    int cnt=0;
};
class Solution {
    TrieNode root;
    void insert(string str){
        auto node = &root;
        for(char ch:str){
            if(!node->next[ch-'a']){
                node->next[ch-'a'] = new TrieNode();
            }
            node->next[ch-'a']->cnt++;
            node = node->next[ch-'a'];
        }
    }

    int count(string str){
        auto node = &root;
        int ans =0;
        for(char ch:str){
            ans +=node->next[ch-'a']->cnt;
            node = node ->next[ch-'a'];
        }
        return ans;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for(string word:words){
            insert(word);
        }
        vector<int> ans(words.size());
        for(int i=0;i<ans.size();i++){
            ans[i] = count(words[i]);
        }
        return ans;
    }
};