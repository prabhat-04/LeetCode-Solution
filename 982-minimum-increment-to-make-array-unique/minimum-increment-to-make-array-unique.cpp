class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        unordered_set<int> s;
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=1;i<nums.size();i++){
            int temp = nums[i];
            nums[i] = max(nums[i],nums[i-1]+1);
            ans += nums[i]-temp;
        }
        return ans;
    }
};