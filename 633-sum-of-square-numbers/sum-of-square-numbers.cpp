class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long i=0;i*i<=c;i++){
            int b = c - int(i*i);
            if(solve(0,b,b)) return true;
        }
        return false;
    }

    bool solve(long l,long h,long  n){
        if(l>h) return false;
        long mid = l +(h-l)/2;
        if(mid*mid == n) return true;
        if(mid*mid>n) return solve(l,mid-1,n);
        return solve(mid+1,h,n);
    }
};