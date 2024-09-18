class Solution {
    static bool cmp(string &a,string &b){
       return (a+b) >(b+a);
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        int zero=0;
        for(int i=0;i<nums.size();i++){
            vec.push_back(to_string(nums[i]));
            if(nums[i]==0) zero++;
        }
        if(zero==nums.size()) return "0";
        sort(vec.begin(),vec.end(),cmp);
        string ans= "";
        for(int i=0;i<vec.size();i++)
            ans+=vec[i];
        return ans;
    }
};