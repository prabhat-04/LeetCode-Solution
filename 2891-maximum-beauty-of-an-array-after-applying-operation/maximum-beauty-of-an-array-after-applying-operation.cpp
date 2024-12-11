class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int limit = 2*k;
        int i=0,j=0;
        int ans = INT_MIN;
        while(j<nums.size()){
            while(i<j && nums[j]-nums[i]>limit){
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};