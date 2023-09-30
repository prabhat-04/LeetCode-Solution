class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int num = INT_MIN;
        stack<int> st;
        for(int i = nums.size()-1;i>=0;i--){
            if(nums[i]<num)
                return true;
            while(!st.empty() && st.top()<nums[i]){
                num = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};