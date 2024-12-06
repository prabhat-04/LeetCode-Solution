class Solution {
public:
    int maxCount(vector<int>& banned, int n,long long  int maxSum) {
        unordered_set<int> ban(banned.begin(), banned.end());
        int sum = 0, count = 0;

        for (int i = 1; i <= n; ++i) {
            if (ban.find(i) != ban.end()) continue; 
            if (sum + i > maxSum) break;
            sum += i;
            count++;
        }
        return count;
    }
};