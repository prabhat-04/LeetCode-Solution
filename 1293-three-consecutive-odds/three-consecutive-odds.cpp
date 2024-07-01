class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n-2;i++){
            int x = arr[i];
            int y = arr[i+1];
            int z = arr[i+2];
            if(x%2!=0 && y%2!=0 && z%2!=0){
                return true;
            }
        }
        return false;
    }
};