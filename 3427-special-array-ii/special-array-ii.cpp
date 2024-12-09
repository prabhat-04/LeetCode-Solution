class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> ans;
        vector<int> vec(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]%2 == nums[i-1]%2)
                vec[i]= vec[i-1]+1;
            else
                vec[i]=vec[i-1];
        }
        for(auto it: queries){
            ans.push_back(vec[it[1]] - vec[it[0]]==0);
        }
        return ans;
    }
};