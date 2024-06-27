class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> freq;
        unordered_set<int> st;
        for(auto it:edges){
            freq[it[0]]++;
            freq[it[1]]++;
            st.insert(it[0]);
            st.insert(it[1]);
        }
        for(auto it:freq){
            if(it.second==st.size()-1)
                return it.first;
        }
        return -1;
    }
};