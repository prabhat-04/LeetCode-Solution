class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bit(24,0);
        for(int num:candidates){
            int i=0;
            while(num>0){
                if(num&1){
                    bit[i]++;
                }
                i++;
                num = num>>1;
            }
        }
        int ans=INT_MIN;
        for(int x:bit){
            ans = max(ans,x);
        }
        return ans;
    }
};