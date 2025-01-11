class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size()) return false;
        if(k==s.size()) return true;
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        int cnt=0;
        for(auto it:mp){
            if(it.second & 1==1) cnt++;
        }
        if(cnt>k) return false;
        else return true;
    }
};