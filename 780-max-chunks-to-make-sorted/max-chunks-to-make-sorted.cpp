class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxi = INT_MIN;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            maxi = max(arr[i],maxi);
            if(i==maxi) ans++;
        }
        return ans;
    }
};