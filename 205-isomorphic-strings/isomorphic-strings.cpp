class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp,dp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]]!=t[i]) return false;
            if(dp.find(t[i])!=dp.end() && dp[t[i]]!=s[i]) return false;
            mp[s[i]] = t[i];
            dp[t[i]] = s[i];
        }
        return true;
    }
};