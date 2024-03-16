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
    void rec(TreeNode* root ,vector<int> &temp,int k){
        if(!root) return ;
        if(temp.size()==k) return;
        rec(root->left,temp,k);
        temp.push_back(root->val);
        rec(root->right,temp,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> temp;
        rec(root,temp,k);
        return temp[k-1];
    }
};