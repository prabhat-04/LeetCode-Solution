class Solution {
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> vec(words.size());
        for(int i=0;i<words.size();i++){
            if(isVowel(words[i][0]) && isVowel(words[i][words[i].size()-1])){
                vec[i]=1;
            }
            else{
                vec[i]=0;
            }
            if(i>0) vec[i]+=vec[i-1];
        }
        vector<int> ans;
        for(auto &it:queries){
            if(it[0]==0) ans.push_back(vec[it[1]]);
            else{
                ans.push_back(vec[it[1]]-vec[it[0]-1]);
            }
        }
        return ans;
    }
};