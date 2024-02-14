class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size();
        vector<int>ans(n);
        int pos=0,neg=1;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                ans[pos]=nums[i];
                pos+=2;
            }
            else{
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        return ans;

    }
};