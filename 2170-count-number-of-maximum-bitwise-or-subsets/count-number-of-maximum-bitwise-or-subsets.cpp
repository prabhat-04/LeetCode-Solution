int speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();


class Solution {
    int solve(vector<int> &nums,int ind,int curr,int maxi){
        if(ind == nums.size()){
            return (curr==maxi)?1:0;
        }
        int x = solve(nums,ind+1,curr,maxi);
        int y = solve(nums,ind+1,curr|nums[ind],maxi);
        return x+y;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(auto &it:nums){
            maxi |= it;
        }
        return solve(nums,0,0,maxi);
    }
};