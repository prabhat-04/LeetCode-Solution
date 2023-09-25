class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum+=(int)s[i];
        }
        int sum2=0;
        for(int i=0;i<t.size();i++){
            sum2+=(int)t[i];
        }
        int ans = sum2 - sum;
        return ans;
    }
};