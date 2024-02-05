class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> temp;
        for(auto ch:s){
            temp[ch]++;
        }
        for(int i=0;i<s.size();i++){
            if(temp[s[i]]==1)
                return i;
        }
        return -1;
    }
};