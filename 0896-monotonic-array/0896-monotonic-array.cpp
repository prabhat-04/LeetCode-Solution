class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int x=1,y=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<=nums[i])
                x++;
            if(nums[i-1]>=nums[i])
                y++;
        }
        if(x==nums.size() || y==nums.size())
            return true;
        else 
            return false;
    }
};