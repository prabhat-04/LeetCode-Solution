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
    void postorder(TreeNode* node, vector<TreeNode*>& remainingTrees, unordered_set<int>& toDeleteSet, TreeNode* parent, bool isLeftChild) {
        if (!node) return;
        postorder(node->left, remainingTrees, toDeleteSet, node, true);
        postorder(node->right, remainingTrees, toDeleteSet, node, false);
        if (toDeleteSet.find(node->val) != toDeleteSet.end()) {
            if (node->left) remainingTrees.push_back(node->left);
            if (node->right) remainingTrees.push_back(node->right);
            if (parent) {
                if (isLeftChild) parent->left = nullptr;
                else parent->right = nullptr;
            }
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> remainingTrees;

        // If the root is not to be deleted, add it to the result
        if (toDeleteSet.find(root->val) == toDeleteSet.end()) {
            remainingTrees.push_back(root);
        }

        // Perform postorder traversal to delete nodes
        postorder(root, remainingTrees, toDeleteSet, nullptr, true);

        return remainingTrees;
    }
};
