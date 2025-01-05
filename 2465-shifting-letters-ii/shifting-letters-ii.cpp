class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        if(s=="") return s;
        vector<int> vec(s.size()+1,0);
        for(auto &it:shifts){
            if(it[2]==1){
                vec[it[0]]+=1;
                vec[it[1]+1]-=1;
            }
            else{
                vec[it[0]]-=1;
                vec[it[1]+1]+=1;
            }
        }

        for (int i = 0; i < s.size(); ++i) {
            if(i>0)
                vec[i] += vec[i - 1];
            int shift = vec[i] % 26; 
            int newChar = s[i] + shift;

            if (newChar > 'z') {
                newChar -= 26;
            } else if (newChar < 'a') {
                newChar += 26;
            }

            s[i] = newChar;
        }
        return s;
    }
};