#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Max-heap to store {improvement, index}
        priority_queue<pair<double, int>> maxHeap;

        // Calculate initial improvement and push into the max-heap
        for (int i = 0; i < classes.size(); i++) {
            int pass = classes[i][0], total = classes[i][1];
            double improvement = (double)(pass + 1) / (total + 1) - (double)pass / total;
            maxHeap.push({improvement, i});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto curr = maxHeap.top();
            maxHeap.pop();

            int index = curr.second;
            classes[index][0]++; // Add one passing student
            classes[index][1]++; // Add one total student

            // Recalculate improvement and push back into the heap
            int pass = classes[index][0], total = classes[index][1];
            double improvement = (double)(pass + 1) / (total + 1) - (double)pass / total;
            maxHeap.push({improvement, index});
        }

        // Calculate the final average pass ratio
        double ans = 0;
        for (const auto& cls : classes) {
            ans += (double)cls[0] / cls[1];
        }
        return ans / classes.size();
    }
};
