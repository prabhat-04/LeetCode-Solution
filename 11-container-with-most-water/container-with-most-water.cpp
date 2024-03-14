class Solution {
public:
    int maxArea(vector<int>& height) {
        std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
        int l=0,r=height.size()-1;
        int ans = INT_MIN;
        while(l<r){
            ans = max(ans,min(height[l],height[r])*(r-l));
            if(height[l]<height[r]) l++;
            else r--;
        }
        return ans;
    }
};