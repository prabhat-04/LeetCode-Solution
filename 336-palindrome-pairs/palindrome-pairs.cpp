class Solution {
public:

    bool isPalindrome(string &word){
        int i=0,j=word.size()-1;
        while(i<j){
            if(word[i]!=word[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string,int> mp;
        for(int i = 0; i < words.size(); i++) {
             string key = words[i];
             reverse(key.begin(), key.end());
             mp[key] = i;
         }

        if(mp.find("")!=mp.end()){
            for(int i=0;i<words.size();i++){
                if(i==mp[""]) continue;
                if(isPalindrome(words[i]))
                    ans.push_back({mp[""],i});
            }
        }


        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                string left = words[i].substr(0,j);
                string right = words[i].substr(j,words[i].size()-j);

                if(mp.find(left)!=mp.end() && isPalindrome(right) && mp[left]!=i)
                    ans.push_back({i,mp[left]});
                if(mp.find(right)!=mp.end() && isPalindrome(left) &&mp[right]!=i)
                    ans.push_back({mp[right],i});
            }
        }
        return ans;
    }
};