class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0,currSum=0;
        for(auto &it:nums){
            sum = (sum + it)%p;
        }
        if(sum%p==0) return 0;
        int target = sum %p;
        int ans = nums.size();
        for(int i=0;i<nums.size();i++){
            currSum = (currSum + nums[i])%p;
            int needed = (currSum - target+p)%p;
            if(mp.find(needed)!=mp.end()){
                ans = min(ans,i-mp[needed]);
            }
            mp[currSum]  =i;
        }
        return ans==nums.size()?-1:ans;
    }
};