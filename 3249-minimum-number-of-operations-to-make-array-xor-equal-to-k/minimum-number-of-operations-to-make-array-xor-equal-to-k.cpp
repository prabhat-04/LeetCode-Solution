class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<32;i++){
            int temp=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]%2==1)    temp^=1;
                nums[j]=nums[j]>>1;
            }
            if((k%2==0 && temp%2==1)||(k%2==1 && temp%2==0)) ans++;
            k=k>>1;
        }

        return ans;
    }
};