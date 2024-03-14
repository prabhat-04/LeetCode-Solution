class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp; 
        int sum=0,ans=0;
        for(auto it :nums){
            sum+=it;
            int x = sum-goal;
            if(x==0) ans++;
            if(mp.find(x)!=mp.end()) ans+=mp[x];
            mp[sum]++;
        } 
        return ans;
    }
};