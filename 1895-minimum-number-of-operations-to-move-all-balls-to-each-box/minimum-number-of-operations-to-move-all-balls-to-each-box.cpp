class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>ans(n,0);
        int sum1=0,cnt1=0;
        int sum2=0,cnt2=0;
        for(int i=0;i<n;i++){
            ans[i]+=sum1;
            cnt1 += boxes[i]-'0';
            sum1+=cnt1;

            int j=n-i-1;
            ans[j]+=sum2;
            cnt2 += boxes[j]-'0';
            sum2+= cnt2;
        }
        return ans;
    }
};