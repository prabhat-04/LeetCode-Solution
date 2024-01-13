class Solution {
public:
    int minSteps(string s, string t) {
        ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int ans=0;
        for(int i=0;i<t.size();i++){
            if(mp.find(t[i])==mp.end() || mp[t[i]]<=0)
                ans++;
            else{
                mp[t[i]]--;
            }
        }
        return ans;
    }
};