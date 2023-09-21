class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>m)
            return findMedianSortedArrays(nums2,nums1);
        int l=0,r=n;
        while(l<=r){
            int mid = (l+r)/2;
            int leftASize = mid;
            int leftBSize = (n+m+1)/2 - mid;
            double leftA = leftASize > 0 ? nums1[leftASize-1]:INT_MIN;
            double leftB = leftBSize > 0 ? nums2[leftBSize-1]:INT_MIN;
            double rightA = leftASize < n ? nums1[leftASize]:INT_MAX;
            double rightB = leftBSize < m ? nums2[leftBSize]:INT_MAX;
            if(leftA<=rightB && leftB<=rightA){
                if((n+m)%2==0)
                    return (max(leftA,leftB)+min(rightA,rightB))/2;
                else
                    return max(leftA,leftB);
            }
            else if(leftA > rightB)
                r = mid-1;
            else
                l = mid+1;
        }
        return 0.0;
    }
};