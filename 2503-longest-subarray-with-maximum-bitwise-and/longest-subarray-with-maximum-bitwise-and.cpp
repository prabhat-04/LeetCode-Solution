class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++)
            maxi = max(maxi,nums[i]);
        int count =0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(maxi==nums[i]){
                count++;
                ans = max(ans,count);
            }
            else
                count =0;
        }
        return ans;
    }
};