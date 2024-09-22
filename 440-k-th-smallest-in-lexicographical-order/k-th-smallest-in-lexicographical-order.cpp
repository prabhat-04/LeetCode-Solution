class Solution {
    int help(int n,long pre1,long pre2){
        int steps=0;
        while(pre1<=n){
            steps+=min((long)(n+1),pre2) - pre1;
            pre1*=10;
            pre2*=10;
        }
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        int  curr = 1;
        k--;
        while(k>0){
            int temp = help(n,curr,curr+1);
            if(temp<=k){
                curr++;
                k-=temp;
            }
            else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};