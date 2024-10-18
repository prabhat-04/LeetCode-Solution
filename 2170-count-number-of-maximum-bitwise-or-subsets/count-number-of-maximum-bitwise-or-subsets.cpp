int speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();


class Solution {
    int solve(vector<int> &nums,int ind,int curr,int maxi,vector<vector<int>> &memo){
        if(ind == nums.size()){
            return (curr==maxi)?1:0;
        }
        if(memo[ind][curr]!=-1) return memo[ind][curr];
        int x = solve(nums,ind+1,curr,maxi,memo);
        int y = solve(nums,ind+1,curr|nums[ind],maxi,memo);
        return memo[ind][curr] = x+y;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(auto &it:nums){
            maxi |= it;
        }
        vector<vector<int>> memo(n,vector<int> (maxi+1,-1));
        return solve(nums,0,0,maxi,memo);
    }
};