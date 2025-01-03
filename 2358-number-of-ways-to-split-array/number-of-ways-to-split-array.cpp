class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int sum=0;
        for(auto &it:nums) sum+=it;
        long long int curr=0;
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            sum-=nums[i];
            curr+=nums[i];
            if(curr>=sum) ans++;
        }
        return ans;
    }
};