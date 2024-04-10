class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n);
        queue<int> q;
        for(int i=0;i<n;i++) q.push(i);
        vector<int> temp;
        while(!q.empty()){
            // cout<<q.front()<<endl;
            temp.push_back(q.front());
            q.pop();
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        sort(deck.begin(),deck.end());
        for(int i=0;i<temp.size();i++){
            ans[temp[i]]=deck[i];
            // cout<<temp[i]<<" ";
        }
        return ans;
    }
};