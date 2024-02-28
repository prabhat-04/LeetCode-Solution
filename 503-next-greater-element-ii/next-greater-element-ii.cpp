class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n =  nums.size();
        vector<int> ans(n);
        stack<int> st;
        vector<bool> vis(n,false);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i])
                st.pop();
            if(st.empty()){  
                ans[i]=-1;
                vis[i]=true;
            }
            else    ans[i] = st.top();
            st.push(nums[i]);
        }

        for(int i=n-1;i>=0;i--){
            if(vis[i]){
                while(!st.empty() && st.top()<=nums[i])
                    st.pop();
                if(st.empty())  ans[i]=-1;
                else    ans[i] = st.top();
            }
        }
        return ans;
    }
};