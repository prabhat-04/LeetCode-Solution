class Solution {
public:
    int rangeBitwiseAnd(int left, int right){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int cnt = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            cnt++;
        }
        return (left << cnt);
    }
};