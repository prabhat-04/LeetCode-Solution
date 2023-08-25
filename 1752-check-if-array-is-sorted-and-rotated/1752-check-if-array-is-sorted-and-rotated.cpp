class Solution {
public:
    bool check(vector<int>& nums) {
        int flag=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i])
                flag++;
        }
        if(nums[nums.size()-1]>nums[0])
            flag++;
        if(flag<=1)
            return true;
        else
            return false;
    }
};