class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k==0){
            vector<int> ans(code.size(),0);
            return ans;
        }
        int n =code.size();
        vector<int> ans(n);
        int sum=0;
        if(k>0){
            for(int i=1;i<=k;i++)
                sum+=code[i];
            ans[0]=sum;
            for(int i=1;i<n;i++){
                sum-=code[i];
                sum+=code[(i+k)%n];
                ans[i]=sum;
            }
        }
        else{
            k=-k;
            for(int i=n-1,cnt=0;i>=0 && cnt<k;i--,cnt++){
                sum+=code[i];
            }
            ans[0]=sum;
            for(int i=1;i<n;i++){
                sum-=code[(n-k+i-1)%n];
                sum+=code[i-1];
                ans[i]=sum;
            }
        }
        return ans;
    }
};