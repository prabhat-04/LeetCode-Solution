class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sen) {
        unordered_set<string>dict;
        for(auto it:dictionary){
            dict.insert(it);
        }
        string curr="",ans="";
        for(int i=0;i<sen.size();i++){
            curr+=sen[i];
            if(sen[i]==' '){
                ans+=curr;
                curr="";
                continue;
            }

            if(dict.find(curr)!=dict.end()){
                ans+=curr+" ";
                curr="";
                while(i<sen.size() && sen[i]!=' ')
                    i++;
            }
        }
        if(ans[ans.size()-1]==' ')
            ans.pop_back();
        if(curr.size()>0)
            ans+=(" " +curr);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();