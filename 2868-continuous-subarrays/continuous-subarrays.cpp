class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> dq1,dq2;
        long long ans = 0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            while(!dq1.empty() && nums[dq1.back()]>nums[i])
                dq1.pop_back();
            dq1.push_back(i);
            while(!dq2.empty() && nums[i]>nums[dq2.back()] )
                dq2.pop_back();
            dq2.push_back(i);
            while(!dq1.empty() && !dq2.empty() && nums[dq2.front()]-nums[dq1.front()]>2){
                if(dq2.front()<dq1.front()){
                    l=dq2.front()+1;
                    dq2.pop_front();
                }
                else{
                    l = dq1.front()+1;
                    dq1.pop_front();
                }
            }
            ans += i-l+1;
        }
        return ans;
    }
};