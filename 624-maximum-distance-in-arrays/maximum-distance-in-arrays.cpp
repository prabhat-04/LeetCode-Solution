class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = arrays[0][0];
        int biggest = arrays[0].back();

        int ans = 0;
        for(int i=1;i<arrays.size();i++){
            ans = max(ans,abs(arrays[i].back() - smallest));
            ans = max(ans,abs(biggest - arrays[i][0]));
            smallest = min(smallest,arrays[i][0]);
            biggest = max(biggest,arrays[i].back());
        }
        return ans;
    }
};