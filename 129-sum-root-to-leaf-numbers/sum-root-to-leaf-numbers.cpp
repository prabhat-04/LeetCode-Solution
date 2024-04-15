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
    void help(TreeNode * root,int curr,int &ans){
        if(!root){
            return;
        }
        curr = (curr*10)+root->val;
        if(!root->left && !root->right){
            ans+=curr;
            return;
        }
        help(root->left,curr,ans);
        help(root->right,curr,ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans =0;
        help(root,0,ans);
        return ans;
    }
};