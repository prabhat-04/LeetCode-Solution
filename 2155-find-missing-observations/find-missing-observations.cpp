class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum =0;
        for(int x:rolls)
            sum+=x;
        int req = mean * (n + rolls.size()) - sum;
        if(req > 6*n || req<n)
            return {};
        int rem = req%n;
        vector<int> ans(n,req/n);
        for(int i=0;i<rem;i++){
            ans[i]++;
        }
        return ans;
    }
};

int speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
