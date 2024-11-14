class Solution {
    bool feasible(int n,vector<int> quantities,int mid){
        // cout<<mid<<endl;
        int i=0,j=0;
        while(i<n && j<quantities.size()){
            if(quantities[j]>=mid){
                quantities[j]-=mid;
            }
            else{
                quantities[j]=0;
            }
            if(quantities[j]==0) j++;
            i++;
        }
        // cout<<quantities[quantities.size()-1]<<endl;
        if(quantities[quantities.size()-1]==0) return true;
        return false;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int right = *max_element(quantities.begin(),quantities.end());
        int left =0;
        while(left<right){
            int mid = left+ (right-left)/2;
            if(feasible(n,quantities,mid)){
                right=mid;
            }
            else
                left=mid+1;
        }
        return left;
    }
};