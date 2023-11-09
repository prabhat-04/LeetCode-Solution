class Solution {
public:
    int countHomogenous(string s) {
        int i=0;
        long long ans=0;
        for(int j=0;j<s.size();j++){
            if(s[j]==s[i]){
                ans+=(j-i+1);   
            }
            else{
                ans+=1;
                i=j;
            }
        }
        return (int)(ans%1000000007);
    }
};