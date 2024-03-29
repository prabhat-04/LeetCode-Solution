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

 int speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
    int help(TreeNode *root){
        if(!root) return INT_MAX;
        if(!root->left && !root->right) return 1;
        return 1 + min(help(root->left),help(root->right));
    }
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return help(root);
        // return ans;
    }
};