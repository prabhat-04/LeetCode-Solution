class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDis = INT_MAX,sum=0;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j=i+1,k=nums.size()-1;
            int tar = target - nums[i];
            while(j<k){
                if(minDis > abs(nums[i]+nums[j]+nums[k]-target)){
                    minDis = abs(nums[i]+nums[j]+nums[k]-target);
                    sum = nums[i]+nums[j]+nums[k];
                }
                if(nums[j]+nums[k]>=tar) k--;
                else j++;
            }
        }
        return sum;
    }
};