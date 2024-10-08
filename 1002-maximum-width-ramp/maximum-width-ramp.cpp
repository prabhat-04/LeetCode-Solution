class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<int> st;
        st.push(0);
        for(int i=1;i<nums.size();i++){
            if(st.empty() || (nums[st.top()]>nums[i])){
                st.push(i);
            }
        }

        int ans =0;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                ans = max(ans,i-st.top());
                st.pop();
            }
            if(st.empty()) break;
        }
        return ans;
    }
};