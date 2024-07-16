/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* LCA(TreeNode *root, int start, int dest) {
        if (!root || root->val == start || root->val == dest) return root;
        TreeNode* left = LCA(root->left, start, dest);
        TreeNode* right = LCA(root->right, start, dest);
        return !left ? right : !right ? left : root;
    }

    bool find(TreeNode *root, int val, string &path) {
        if (!root) return false;
        if (root->val == val) return true;
        
        path.push_back('L');
        if (find(root->left, val, path)) return true;
        path.pop_back();
        
        path.push_back('R');
        if (find(root->right, val, path)) return true;
        path.pop_back();
        
        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca = LCA(root, startValue, destValue);
        string pathToStart = "", pathToDest = "";
        
        // Find path from LCA to startValue
        find(lca, startValue, pathToStart);
        // Find path from LCA to destValue
        find(lca, destValue, pathToDest);
        
        // Convert pathToStart to 'U'
        string result(pathToStart.size(), 'U');
        result += pathToDest;
        
        return result;
    }
};
