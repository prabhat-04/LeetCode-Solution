class Solution {
public:
    void helper(unordered_map<int,string>&mp,vector<string>&ans,string digits,int i,string temp){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<mp[digits[i]-'0'].size();j++){
            helper(mp,ans,digits,i+1,temp+mp[digits[i]-'0'][j]);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return{};
        vector<string> ans;
        unordered_map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        helper(mp,ans,digits,0,"");
        return ans;
    }
};