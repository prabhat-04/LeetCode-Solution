class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,zero=0;
        ios::sync_with_stdio(false);
        cin.tie(0);
        int ans = INT_MIN;
        while(j<nums.size()){
            if(nums[j]==0) zero++;
            while(i<=j && zero>k){
                if(nums[i]==0) zero--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};