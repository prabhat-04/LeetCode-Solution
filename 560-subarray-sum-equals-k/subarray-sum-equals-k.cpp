class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int cnt=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
                cnt+=mp[sum-k];
            }
            if(sum-k==0) cnt++;
            mp[sum]++;
        }
        return cnt;
    }
};