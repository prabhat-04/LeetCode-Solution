class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr2.size();i++){
            mp[arr2[i]]=i;
        }
        sort(arr1.begin(),arr1.end(),[&](int &a,int&b){
            if(mp.find(a)!=mp.end() && mp.find(b)!=mp.end())
                return mp[a]<mp[b];
            else if(mp.find(a)==mp.end() && mp.find(b)==mp.end())
                return a<b;
            else if(mp.find(a)!=mp.end())
                return true;
            else
                return false;
        });
        return arr1;
    }
};