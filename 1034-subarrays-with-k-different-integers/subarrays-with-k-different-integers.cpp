class Solution {
public:
    int helper(vector<int> &nums,int k){
        unordered_map<int,int> mp;
        int i=0,j=0,count =0;
        while(j<nums.size()){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        return helper(nums,k) - helper(nums,k-1);
    }
};