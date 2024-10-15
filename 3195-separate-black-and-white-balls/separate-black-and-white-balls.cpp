int speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    long long minimumSteps(string s) {
        int curr=0;
        long long ans =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                ans += i-curr;
                curr++;

            }
        }
        return ans;
    }
};