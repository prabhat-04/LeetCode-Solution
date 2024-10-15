class Solution {
public:
    long long minimumSteps(string s) {
        int zero=0;
        for(char c:s){
            if(c=='0') zero++;
        }
        long long ans =0;
        for(char c:s){
            if(c=='0') zero--;
            else{
                ans += zero;
            }
        }
        return ans;
    }
};