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
public:

    void traverse(TreeNode* root, int currMax, int &ans){
        if(!root) return;

        if(root->val >= currMax){
            ans++;
            currMax = root->val;
        }

        traverse(root->left, currMax, ans);
        traverse(root->right, currMax, ans);
    }
    
    int goodNodes(TreeNode* root) {
        int ans = 0;
        traverse(root, root->val, ans);
        return ans;
    }
};