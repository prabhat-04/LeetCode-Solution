class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long total = 0;
        for(auto &it:gifts){
            pq.push(it);
            total+=it;
        }
        while(k>0 && !pq.empty()){
            int curr = pq.top();
            pq.pop();
            int x = sqrt(curr);
            total= total -curr + x;
            pq.push(x);
            k--;
        }
        return total;
    }
};