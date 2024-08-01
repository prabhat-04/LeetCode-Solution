class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto it:details){
            string temp = "";
            temp+=it[11];
            temp+=it[12];
            if(stoi(temp)>60)
                ans++;
        }
        return ans;
    }
};