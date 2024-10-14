class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long ans = 0;  
        while (k > 0 && !pq.empty()) {
            int topVal = pq.top();
            ans += topVal;
            pq.pop();
            pq.push(ceil(topVal / 3.0));  
            k--;
        }     
        return ans;
    }
};