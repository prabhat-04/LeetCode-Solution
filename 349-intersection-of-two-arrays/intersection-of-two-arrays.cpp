class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> temp,ss;
        for(int i=0;i<nums1.size();i++)
            temp.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++){
            if(temp.find(nums2[i])!=temp.end() && ss.find(nums2[i])==ss.end())
                ans.push_back(nums2[i]);
            ss.insert(nums2[i]);
        }
        return ans;
    }
};