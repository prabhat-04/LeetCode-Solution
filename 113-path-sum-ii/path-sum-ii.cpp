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
    void solve(TreeNode*root,int target,vector<vector<int>> &ans,vector<int> temp){
        if(!root) return ;
        temp.push_back(root->val);
        if(!root->left && !root->right){
            if(target==root->val){
                ans.push_back(temp);
            }
            return;
        }
        solve(root->left,target-root->val,ans,temp);
        solve(root->right,target-root->val,ans,temp);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        solve(root,targetSum,ans,{});
        return ans;
    }
};