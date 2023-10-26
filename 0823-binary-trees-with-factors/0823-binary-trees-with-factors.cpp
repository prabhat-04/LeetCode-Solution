class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1000000007;
        sort(arr.begin(),arr.end());
        unordered_set<int> s(arr.begin(),arr.end());
        unordered_map<int,int> dp;
        for(auto i:arr)
            dp[i]=1;
        for(int i:arr){
            for(int j:arr){
                if(j>sqrt(i))   break;
                if(i%j==0 && s.find(i/j)!=s.end()){
                    long long temp = static_cast<long long>(dp[j]) * dp[i/j];
                    if(i/j==j)
                        dp[i] = (dp[i]+ temp)%mod;
                    else
                        dp[i] = (dp[i] + temp*2)%mod;
                }
            }
        }
        int result=0;
        for(auto &[_,val] :dp){
            result = (result + val)%mod;
        }
        return result;
    }
};