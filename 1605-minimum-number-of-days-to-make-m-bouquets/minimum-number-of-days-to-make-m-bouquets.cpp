class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        

        int left = 0;
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int adjacentFlowers = 0;
            int bouquets = 0;

            for (int i = 0; i < bloomDay.size(); ++i) {
                if (bloomDay[i] <= mid) {
                    adjacentFlowers++;
                } else {
                    adjacentFlowers = 0;
                }

                if (adjacentFlowers >= k) {
                    bouquets++;
                    adjacentFlowers = 0;
                }
            }

            if (bouquets >= m) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};
