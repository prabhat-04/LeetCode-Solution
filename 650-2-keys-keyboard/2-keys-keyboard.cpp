class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        int cnt=0;
        int d=2;
        while(n>1){
            while(n%d==0){
                cnt+=d;
                n/=d;
            }
            d++;
            if (d*d>n) break;
        }
        if(n!=1) return cnt+n;
        return cnt;
    }
};