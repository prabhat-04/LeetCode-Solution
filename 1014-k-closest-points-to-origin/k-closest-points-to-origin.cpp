class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {
        double dis1 = sqrt(double(a[0] * a[0]) + (a[1] * a[1]));
        double dis2 = sqrt(double(b[0] * b[0]) + (b[1] * b[1]));
        if (dis1 < dis2)
            return true;
        return false;
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), cmp);
        vector<vector<int>> ans;
        for (int i = 0; i < min(k, static_cast<int>(points.size())); i++) {
            ans.push_back(points[i]);
        }
        return ans;
    }
};