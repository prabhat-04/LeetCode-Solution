class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4) return 0;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-4;
        int ans = INT_MAX;
        while(j<nums.size()){
            ans = min(ans,nums[j]-nums[i]);
            i++;
            j++;
        }
        return ans;
    }
};