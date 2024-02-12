class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // ios::sync_with_stdio(false);
        // cin.tie(nullptr);
        // cout.tie(nullptr);
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
            if(mp[x]>nums.size()/2)
                return x;
        }
        return -1;
    }
};