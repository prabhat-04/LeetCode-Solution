class Solution {
public:
    void help(int i,vector<int> &nums,vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int j=i;j<nums.size();j++){
            if(s.find(nums[j])==s.end()){
                swap(nums[i],nums[j]);
                help(i+1,nums,ans);
                swap(nums[i],nums[j]);
            }
            s.insert(nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        help(0,nums,ans);
        return ans;
    }
};