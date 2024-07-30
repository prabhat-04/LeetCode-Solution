class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int n = s.size();
        int ans =0;
        for(int i=0;i<n;i++){
            if(!st.empty() && s[i]=='a' && st.top()=='b'){
                st.pop();
                ans++;
            }
            else
                st.push(s[i]);
        }
        return ans;
    }
};