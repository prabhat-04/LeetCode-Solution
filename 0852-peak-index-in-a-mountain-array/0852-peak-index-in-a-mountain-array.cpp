class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size()<3)
            return 0;
        int ans = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[ans]<arr[i])
                ans = i;
        }
        return ans;
    }
};