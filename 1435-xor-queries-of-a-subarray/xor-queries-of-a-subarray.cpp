class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        if(arr.size()==0)
            return {};
        vector<int> ans;
        vector<int> prefix(arr.size());
        prefix[0] = arr[0];
        for(int i=1;i<arr.size();i++){
            prefix[i] = arr[i] ^ prefix[i-1];
            // cout<<prefix[i]<<endl;
        }
        for(auto &it : queries){
            if(it[0]==0)
                ans.push_back(prefix[it[1]]);
            else
                ans.push_back(prefix[it[1]] ^ prefix[it[0]-1]);
        }
        return ans;
    }
};