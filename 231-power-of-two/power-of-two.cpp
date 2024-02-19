class Solution {
public:
    bool isPowerOfTwo(int n) {
        // ios::sync_with_stdio(false);
        // cin.tie(nullptr);
         return n && !(n & (n-1l));
    }
};