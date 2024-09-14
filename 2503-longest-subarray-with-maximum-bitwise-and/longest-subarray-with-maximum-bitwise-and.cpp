class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = nums[0];
        int ans = 1;
        int curr = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                curr = 1;
                ans=1;
            }
            else if(nums[i]==maxi){
                curr++;
                ans = max(ans,curr);
            }
            else
                curr=0;
        }
        return ans;
    }
};