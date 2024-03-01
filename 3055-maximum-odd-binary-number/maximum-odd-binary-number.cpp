class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        string ans(n,'0');
        ans[n-1]='1';
        int k=0,flag=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(flag==0)
                    flag=1;
                else{
                    ans[k++]='1';
                }
            }
        }
        return ans;
    }
};