class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int d = max(abs(fx-sx),abs(fy-sy));
        return d>0 ? t>=d : t!=1;
    }
};