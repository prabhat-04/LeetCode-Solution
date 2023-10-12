/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peak(MountainArray &m){
        int l=0,r=m.length()-2;
        while(l<r){
            int mid =(l+r)/2;
            if(m.get(mid) < m.get(mid+1))
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }

    int search1(MountainArray &m,int target,int l,int r){
        while(l<=r){
            int mid=(l+r)/2;
            if(m.get(mid)==target)
                return mid;
            else if(target<m.get(mid))
                r=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }

    int search2(MountainArray &m,int target,int l,int r){
        while(l<=r){
            int mid=(l+r)/2;
            if(m.get(mid)==target)
                return mid;
            else if(target<m.get(mid))
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int p = peak(mountainArr);
        // return p;
        int x = search1(mountainArr,target,0,p);
        if(x!=-1)
            return x;
        return search2(mountainArr,target,p+1,mountainArr.length()-1);
    }
};