class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ancestors(n);
        vector<vector<int>> adjacencyList(n);
        
        for (const auto& edge : edges) {
            adjacencyList[edge[1]].push_back(edge[0]);
        }
        
        for (int node = 0; node < n; ++node) {
            ancestors[node] = findAncestors(node, adjacencyList, n);
            sort(ancestors[node].begin(), ancestors[node].end());
        }
        
        return ancestors;
    }

private:
    vector<int> findAncestors(int node, const vector<vector<int>>& adjacencyList, int n) {
        vector<int> result;
        queue<int> bfsQueue;
        bfsQueue.push(node);
        vector<bool> visited(n, false);
        visited[node] = true;
        
        while (!bfsQueue.empty()) {
            int currentNode = bfsQueue.front();
            bfsQueue.pop();
            
            if (currentNode != node) {
                result.push_back(currentNode);
            }
            
            for (const auto& neighbor : adjacencyList[currentNode]) {
                if (!visited[neighbor]) {
                    bfsQueue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        
        return result;
    }
};