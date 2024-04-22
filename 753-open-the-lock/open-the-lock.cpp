class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s,vis;
        for(auto x:deadends){
            s.insert(x);
        }
        if(s.find("0000")!=s.end()) return -1;
        if(target=="0000") return 0;
        if(s.find(target)!=s.end()) return -1;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            string x = curr.first;
            int move = curr.second;
            if(x==target) return move;

            for(int i=0;i<4;i++){
                for(int dir:{-1,1}){
                    int ch = (x[i]-'0'+dir+10)%10;
                    string newC = x;
                    newC[i] = '0' + ch;

                    if(vis.find(newC)==vis.end() && s.find(newC)==s.end()){
                        vis.insert(newC);
                        q.push({newC,move+1});
                    }

                }
            }
        }
        return -1;
    }
};