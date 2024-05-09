class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        int temp=0;
        long long ans =0;
        for(int i=0;i<happiness.size() && k>0;i++){
            // ans+=happiness[i];
            if(happiness[i]-temp>0)
                ans+=(happiness[i]-temp);
            temp++;
            // cout<<i<<" "<<k<<" "<<happiness[i]<<" "<<ans<<endl;
            k--;
        }
        return ans;
    }
};