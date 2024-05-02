class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s;
        int ans =INT_MIN;
        for(int it:nums){
            if(s.count(-it)>0) {
                ans=max(ans,abs(it));
            }
            s.insert(it);
        }
        return ans==INT_MIN?-1:ans;
    }
};