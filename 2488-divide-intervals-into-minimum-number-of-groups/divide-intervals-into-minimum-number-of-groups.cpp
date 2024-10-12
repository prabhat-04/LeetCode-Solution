class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int> mp;
        for(auto it:intervals){
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        int curr=0,ans=0;
        for(auto it:mp){
            curr+=it.second;
            ans = max(ans,curr);
        }
        return ans;
    }
};