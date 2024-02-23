class Solution {
public:
    static bool mycmp(const string &a,const string &b){
        string l = a+b;
        string r = b+a;
        return l>r;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        int zero=0;
        for(int i=0;i<nums.size();i++){
            vec.push_back(to_string(nums[i]));
            if(nums[i]==0) zero++;
        }
        if(zero==nums.size()) return "0";
        sort(vec.begin(),vec.end(),mycmp);
        string ans="";
        for(int i=0;i<vec.size();i++)
            ans+=vec[i];
        return ans;
    }
};