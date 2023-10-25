class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1)
            return 0;
        int x = pow(2,n-1);
        int y = x/2;
        if(k>y)
            return 1 - kthGrammar(n,k-y);
        return kthGrammar(n-1,k);
    }
};