class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int req = sum -x;
        if(req==0) return nums.size();
        if(req <0) return -1;

        int head=0,tail=0,maxLen=0,mySum=0;
        for(head=0;head<nums.size();head++){
            mySum+=nums[head];
            while(mySum > req){
                mySum-=nums[tail];
                tail++;
            }
            if(mySum==req){
                maxLen = max(maxLen,head-tail+1);
            }
        }
        return maxLen==0? -1 : nums.size()-maxLen;
    }
};