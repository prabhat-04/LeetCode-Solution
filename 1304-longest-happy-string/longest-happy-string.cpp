class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        string ans="";
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            if(ans.length()>=2 and ans[ans.length()-1] == x.second and ans[ans.length()-2]==x.second){
                if(pq.empty()) break;
                auto temp = pq.top();
                pq.pop();
                ans += temp.second;
                if(temp.first-1>0){
                    pq.push({temp.first-1,temp.second});
                }
            }
            else{
                x.first--;
                ans = ans + x.second;
            }

            if(x.first>0){
                pq.push({x.first,x.second});
            }
        }
        return ans;
    }
};