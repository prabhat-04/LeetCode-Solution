class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int x = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                x=i;
                break;
            }
        }
        if(x==0 ){
            for(int i=0;i<nums.size();i++)
                nums[i]*=nums[i];
             return nums;
        }
        
        int y;
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