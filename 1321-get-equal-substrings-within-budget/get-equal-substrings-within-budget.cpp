class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> dp(s.size());
        for(int i=0;i<s.size();i++){
            dp[i]=abs(s[i]-t[i]);
        }
        int i=0,j=0,ans = INT_MIN,curr=0;
        while(j<s.size()){
            curr+=dp[j];
            while(i<=j && curr>maxCost){
                curr-=dp[i];
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};