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
    int dfs(TreeNode *root,int &ans){
        if(!root) return NULL;

        int l = dfs(root->left,ans);
        int r = dfs(root->right,ans);
        ans += abs(l)+abs(r);
        return root->val - 1 + l+r;
    }
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        dfs(root,ans);
        return ans;
    }
};