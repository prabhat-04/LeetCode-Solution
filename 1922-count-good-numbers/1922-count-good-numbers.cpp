class Solution {
public:
int mod =1e9+7;
    long long  ipow(long long base, long long exp)
{
    long long result = 1;
    for (;;)
    {
        if (exp & 1)
            result  = ((result%mod)* (base%mod))%mod;
        exp >>= 1;
        if (!exp)
            break;
        base = ((base%mod)*(base%mod))%mod;
    }

    return result;
}

    int countGoodNumbers(long long n) {
        long long exp = n/2;
        long long ans1,ans2,exp1=exp;
        if(n%2!=0)
            exp1++;
        ans1 = ipow(5,exp1);
        ans2 = ipow(4,exp);
        return ((ans1%mod)*(ans2%mod))%mod;
    }
};