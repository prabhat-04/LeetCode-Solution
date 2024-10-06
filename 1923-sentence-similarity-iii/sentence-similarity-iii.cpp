class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.size()>sentence2.size()) return areSentencesSimilar(sentence2,sentence1);
        stringstream ss1(sentence1),ss2(sentence2);
        string word;
        vector<string> s1Words,s2Words;
        while(ss1>>word) s1Words.push_back(word);
        while(ss2>>word) s2Words.push_back(word);
        int i=0,j=s1Words.size()-1,k=s2Words.size()-1;
        while(i<s1Words.size() && s1Words[i]==s2Words[i])
            ++i;
        while(j>=0 && s1Words[j] == s2Words[k]){
            --j;
            --k;
        }

        return j<i;
    }
};