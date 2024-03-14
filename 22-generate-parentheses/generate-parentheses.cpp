class Solution {
    void solve(vector<string> &ans,string temp,int op,int cl,int n){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(op<n){
            solve(ans,temp+"(",op+1,cl,n);
        }
        if(op>cl)
            solve(ans,temp+")",op,cl+1,n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans,"",0,0,n);
        return ans;
    }
};