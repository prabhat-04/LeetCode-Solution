class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        for(int i=0;i<s.size();){
            int cnt=0;
            int j=i;
            while(j<s.size() && s[j]==s[i]){
                j++;
                cnt++;
            }
            if(cnt>=2){
                ans+=s[i];
                ans+=s[i];
                i=j;
            }
            else{
                ans+=s[i];
                i++;
            }

        }
        return ans;
    }
};