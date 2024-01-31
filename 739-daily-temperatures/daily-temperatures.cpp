class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        stack<int> st;
        vector<int> ans(temp.size());
        for(int i=temp.size()-1;i>=0;i--){
            while(!st.empty() && temp[i]>=temp[st.top()])
                st.pop();
            if(st.empty())
                ans[i]=0;
            else{
                ans[i]=st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};