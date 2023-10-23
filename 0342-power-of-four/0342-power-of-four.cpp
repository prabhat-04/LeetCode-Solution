class Solution {
public:
    bool isPowerOfFour(long long int n) {
        // return true;
        long long int x = ffs(n);
        // cout<<x<<endl;
        return n && !(n&(n-1)) && x%2==1;
    }
};