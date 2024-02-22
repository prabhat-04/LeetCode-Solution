class Solution {
public:
    bool isPalindrome(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void help(int ind,vector<vector<string>> &ans,string &s,vector<string> &temp){
        int n = s.size();
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        for(int j=1;j<=n-ind;j++){
            if(isPalindrome(s.substr(ind,j))){
                temp.push_back(s.substr(ind,j));
                help(ind+j,ans,s,temp);
                temp.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        help(0,ans,s,temp);
        return ans;
    }
};