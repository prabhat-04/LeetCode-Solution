class Solution {
    vector<int> count(string str){
        vector<int> ans(26,0);
        for(char c:str)
            ans[c-'a']++;
        return ans;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> vec(26,0);
        for(auto &word:words2){
            vector<int> temp = count(word);
            for(int i=0;i<26;i++)
                vec[i] = max(vec[i],temp[i]);
        }

        for(auto &word:words1){
            vector<int> temp =  count(word);
            bool flag=true;
            for(int i=0;i<26;i++){
                if(temp[i]<vec[i]){
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans.push_back(word);
        }
        return ans;
    }
};