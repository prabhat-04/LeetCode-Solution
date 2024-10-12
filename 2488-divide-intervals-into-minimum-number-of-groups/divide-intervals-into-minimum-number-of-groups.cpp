class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int,int>> vec;
        for(auto it:intervals){
            vec.push_back({it[0],1});
            vec.push_back({it[1]+1,-1});
        }
        sort(vec.begin(),vec.end());
        int ans = 0,curr=0;
        for(auto it:vec){
            curr+=it.second;
            ans = max(ans,curr);
        }
        return ans;
    }
};