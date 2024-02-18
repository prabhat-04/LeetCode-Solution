class Solution {
public:
    string convert(string s, int numRows) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<char>> v(numRows);
        int i=0;
        while(i<s.size()){
            int j=0;
            while(i<s.size() && j<numRows){
                v[j].push_back(s[i]);
                i++;
                j++;
            }
            j-=2;
            while(i<s.size() && j>0){
                v[j].push_back(s[i]);
                i++;
                j--;
            }
        }

        string ans="";
        for(auto x:v){
            for(char c:x)
                ans+=c;
        }
        return ans;
    }
};