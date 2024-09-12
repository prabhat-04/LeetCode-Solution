class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
       int ans = words.size();
       unordered_set<char> s;
       for(char c : allowed){
           s.insert(c);
       }
       for(int i=0;i<words.size();i++){
           string p = words[i];
           for(int j=0;j<p.size();j++){
               if(s.find(p[j])==s.end()){
                   ans--;
                   break;
               }
           }
       }
       return ans;
    }
};