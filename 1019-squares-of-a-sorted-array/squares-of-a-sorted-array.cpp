class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]>=0)
                r=mid;
            else
                l=mid+1;
        }
        
        int y,x=r;
        if(x==-1) y=nums.size()-1;
        else y=x-1;
        vector<int> ans;
        while(y>=0 && x<nums.size()){
            if((nums[x]*nums[x])<=(nums[y]*nums[y])){
                ans.push_back(nums[x]*nums[x]);
                x++;
            }
            else{
                ans.push_back(nums[y]*nums[y]);
                y--;
            }
        }

        while(y>=0){
            ans.push_back(nums[y]*nums[y]);
            y--;
        }

        while(x<nums.size()){
            ans.push_back(nums[x]*nums[x]);
            x++;
        }
        return ans;
    }
};