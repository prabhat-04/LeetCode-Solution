class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> cnt(26,0);
        vector<bool> visited(26,false);
        for(int i=0;i<s.size();i++)
            cnt[s[i]-'a']++;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            cnt[ch-'a']--;
            if(visited[ch-'a']) continue;

            while(st.size()>0 && st.top()>ch && cnt[st.top()-'a']>0){
                char temp = st.top();
                st.pop();
                visited[temp-'a']=false;
            }
            st.push(ch);
            visited[ch-'a']=true;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};