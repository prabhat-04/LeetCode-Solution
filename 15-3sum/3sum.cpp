class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int target = - nums[i];
                if(nums[j]+nums[k]==target){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int l = nums[j],r=nums[k];
                    while(j<k && nums[j]==l) j++;
                    while(j<k && nums[k]==r) k--;
                }
                else if(nums[j]+nums[k]<target) j++;
                else k--;
            }
        }
        return ans;
    }
};