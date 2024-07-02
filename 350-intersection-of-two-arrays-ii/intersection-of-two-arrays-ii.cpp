class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() < nums2.size())
            return intersect(nums2,nums1);
        sort(nums2.begin(),nums2.end());
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            int left = 0,right =nums2.size()-1;
            while(left<=right){
                int mid =  (right+left)/2;
                if(nums2[mid]==nums1[i]){
                    ans.push_back(nums1[i]);
                    nums2.erase(nums2.begin() + mid);
                    break;
                }
                else if(nums1[i] < nums2[mid])
                    right=mid-1;
                else
                    left=mid+1;
            }
        }
        return ans;
    }
};