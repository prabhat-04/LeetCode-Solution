class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> sortedSet(arr.begin(), arr.end());
    
        unordered_map<int, int> rankMap;
        int rank = 1;
        for (const int& num : sortedSet) {
            rankMap[num] = rank++;
        }
        
        vector<int> ans;
        for (const int& it : arr) {
            ans.push_back(rankMap[it]);
        }
        
        return ans;
    }
};