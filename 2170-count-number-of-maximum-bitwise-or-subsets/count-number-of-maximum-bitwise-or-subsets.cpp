int speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();


class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(auto &it:nums){
            maxi |= it;
        }
        int ans =0,total=1<<n;
        for(int i=0;i<total;i++){
            int curr=0;
            for(int j=0;j<n;j++){
                if((i>>j & 1)==1)
                    curr |= nums[j];
            }
            if(curr==maxi) ans++;
        }
        return ans;
    }
};