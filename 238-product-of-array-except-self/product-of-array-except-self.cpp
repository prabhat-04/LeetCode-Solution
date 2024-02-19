class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size();
        vector<int> pre(n),post(n),ans(n);
        pre[0]=nums[0];
        post[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
            pre[i] = pre[i-1] * nums[i];
        for(int i=n-2;i>=0;i--)
            post[i]= post[i+1] * nums[i];
        
        for(int i=0;i<n;i++){
            int l = i-1>=0?pre[i-1]:1;
            int r = i+1<n?post[i+1]:1;
            ans[i]=l*r;
        }
        return ans;
    }
};