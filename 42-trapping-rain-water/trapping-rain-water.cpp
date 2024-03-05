class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,INT_MAX),right(n,INT_MAX);
        int i=0,j=n-1;
        while(i<n){
            if(i==0)
                left[i]=height[i];
            else
                left[i]=max(left[i-1],height[i]);
            
            if(j==n-1)
                right[j]=height[j];
            else
                right[j]=max(right[j+1],height[j]);
            i++;
            j--;
        }

        int ans = 0;
        i=0;
        while(i<n){
            ans+=(min(left[i],right[i]) - height[i]);
            i++;
        }
        return ans;
    }
};