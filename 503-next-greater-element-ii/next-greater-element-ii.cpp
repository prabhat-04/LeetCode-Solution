class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n =  nums.size();
        vector<int> ans(n);
        stack<int> st;
        vector<int> vec;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i])
                st.pop();
            if(st.empty()){  
                ans[i]=-1;
                vec.push_back(i);
            }
            else    ans[i] = st.top();
            st.push(nums[i]);
        }

        for(int i=0;i<vec.size();i++){
            while(!st.empty() && st.top()<=nums[vec[i]])
                st.pop();
            if(st.empty()){  
                ans[vec[i]]=-1;
            }
            else    ans[vec[i]] = st.top();
        }
        return ans;
    }
};