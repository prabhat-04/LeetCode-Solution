class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int i = 0, j = 0;
        int ans = 0;

        while (j < nums.size()) {
            // Maintain maxDeque to be a decreasing deque
            while (!maxDeque.empty() && nums[j] > nums[maxDeque.back()]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(j);

            // Maintain minDeque to be an increasing deque
            while (!minDeque.empty() && nums[j] < nums[minDeque.back()]) {
                minDeque.pop_back();
            }
            minDeque.push_back(j);

            // Check the condition
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                if (i == maxDeque.front()) {
                    maxDeque.pop_front();
                }
                if (i == minDeque.front()) {
                    minDeque.pop_front();
                }
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};
