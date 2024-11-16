class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1,-1);
        deque<int> dq;
        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front()<i-k+1)
                dq.pop_front();
            if(!dq.empty() && nums[i]!=nums[i-1]+1)
                dq.clear();
            dq.push_back(i);
            if(i>=k-1){
                if(dq.size()==k)
                    ans[i-k+1]=nums[dq.back()];
                else
                    ans[i-k+1]=-1;
            }
        }
        return ans;
    }
};