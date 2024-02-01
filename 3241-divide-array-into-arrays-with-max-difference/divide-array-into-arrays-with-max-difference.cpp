class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(nums.size()%3!=0)
            return{};
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=3){
            if(i+2<n && nums[i+2]-nums[i]<=k){
                ans.push_back({nums[i],nums[i+1],nums[i+2]});
            }
            else
                return {};
        }
        return ans;
    }
};