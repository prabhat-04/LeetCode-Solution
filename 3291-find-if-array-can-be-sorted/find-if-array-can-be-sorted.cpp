class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = __builtin_popcount(nums[0]);
        int maxi = nums[0];
        int mini = nums[0];

        int maxPrev = INT_MIN;
        for(int i=1;i<nums.size();i++){
            if(__builtin_popcount(nums[i])==n){
                maxi = max(maxi,nums[i]);
                mini = min(mini,nums[i]);
            }
            else{
                if(mini < maxPrev) return false;
                maxPrev = maxi;
                maxi =  nums[i];
                mini = nums[i];
                n = __builtin_popcount(nums[i]);
            }
        }
        if(mini < maxPrev)
            return false;
        return true;
    }
};