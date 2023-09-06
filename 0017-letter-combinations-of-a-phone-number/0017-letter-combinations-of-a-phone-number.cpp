class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};
        
        vector<string> pad = {{},{},{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
        vector<string> ans;
        ans.push_back("");
        for(auto s : digits){
            vector<string> temp;
            for(auto x : pad[ s - '0']){
                for(auto y : ans){
                    temp.push_back( y + x);
                }
            }
            ans.clear();
            ans = temp;
        }
        return ans;
        
    }
};