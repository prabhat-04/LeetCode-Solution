class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<array<int,3>> times;
        for(auto &it:events){
            times.push_back({it[0],1,it[2]});
            times.push_back({it[1]+1,0,it[2]});
        }
        sort(begin(times),end(times));
        int ans =0,val=0;
        for(auto &it:times){
            if(it[1]){
                ans = max(ans,val+it[2]);
            }
            else{
                val = max(val,it[2]);
            }
        }
        return ans;
    }
};