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
    bool valid(TreeNode* root,long long int left,long long int right){
        if(!root) return true;
        if(root->val <= left || root->val >= right) return false;
        return valid(root->left,left,root->val) && valid(root->right,root->val,right) ;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        return valid(root,-1000000000000,1000000000000);
    }
};