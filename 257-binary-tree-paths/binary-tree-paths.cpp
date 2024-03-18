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
    void help(TreeNode *root,vector<string> &ans,string temp){
        if(!root) return;
        temp+=to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(temp);
            return;
        }
        temp+="->";
        help(root->left,ans,temp);
        help(root->right,ans,temp);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> ans;
        help(root,ans,"");
        return ans;
    }
};