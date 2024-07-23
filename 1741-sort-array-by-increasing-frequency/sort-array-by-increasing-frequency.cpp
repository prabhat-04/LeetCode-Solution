class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> no;
        for(auto it: nums){
            no[it]++;
        }
        vector<pair<int,int>> A;
        for(auto& it : no){
            A.push_back({it.second , it.first});
        }
        sort(A.begin(),A.end(),cmp);
        vector<int> ans;
        for(auto& it: A){
            for(int i = 0;i< it.first ;i++){
                ans.push_back(it.second);
            }
        }
        return ans;

    }

    static bool cmp(pair<int, int>& a, pair<int, int>& b)
    {
        if(a.first==b.first)
            return a.second > b.second ;
        return a.first < b.first;
    }
};