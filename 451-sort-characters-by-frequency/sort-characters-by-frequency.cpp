class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        for(auto x:s) m[x]++;

priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;

    for(auto x:m){
        pq.push(make_pair(x.second,x.first));
    }

    string p="";
    while(!pq.empty()){
        pair<int,char>q=pq.top();
        int k1=q.first;
        while(k1--){
            p+=q.second;
        }
        pq.pop();
    }
      reverse(p.begin(),p.end());
        return p;
    }
};