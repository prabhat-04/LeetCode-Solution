class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        // unordered_map<int,int> mp;
        // for(int i=0;i<nums2.size();i++)
        //     mp[nums2[i]]=i;

        vector<pair<int,int>> vec;
        for(int i=0;i<nums2.size();i++)
            vec.push_back({nums2[i],i});

        vector<int> ans(nums1.size(),-1);
        
        sort(nums1.begin(),nums1.end());
        sort(vec.begin(),vec.end());
        int j=nums1.size()-1;
        int i=j;
        while(i>=0 && j>=0){
            if(nums1[i]>vec[j].first){
                ans[vec[j].second]=nums1[i];
                i--;
                j--;
            }
            else
                j--;
        }
        for(int k=0;k<ans.size();k++){
            if(ans[k]==-1){
                ans[k]=nums1[i];
                // cout<<i<<endl;
                i--;
            }
        }
        return ans;
    }
};