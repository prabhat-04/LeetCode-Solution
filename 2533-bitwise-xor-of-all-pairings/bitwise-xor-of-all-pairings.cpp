class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int xor1=0;
        if(n1 & 1){
            for(auto &it:nums2) xor1^=it;
        }
        else
            xor1=0;
        int xor2=0;
        if(n2&1){
            for(auto &it:nums1) xor2^=it;
        }
        else xor2=0;
        return xor1^xor2;
    }
};