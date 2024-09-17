class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss(s1);
        string word;
        unordered_map<string,int> mp;
        while (ss >> word) {
            mp[word]++;
        }
        stringstream st(s2);
        while (st >> word) {
            mp[word]++;
        }
        vector<string> ans;
        for(auto &it:mp){
            if(it.second==1)
                ans.push_back(it.first);
        }
        return ans;
    }
};