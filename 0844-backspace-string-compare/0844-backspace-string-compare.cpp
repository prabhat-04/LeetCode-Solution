class Solution {
public:

    string build(string s){
        string ans="";
        for(char c: s){
            if(c != '#')
                ans+=c;
            else if(ans.size()>0)
                ans.pop_back();
        }
        return ans;
    }

    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }

    
};