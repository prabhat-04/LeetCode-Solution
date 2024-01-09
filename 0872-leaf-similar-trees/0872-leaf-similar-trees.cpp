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
    void inorder(TreeNode *root,vector<int> &ans){
        if(root==NULL)
            return;
        inorder(root->left,ans);
        if(root->left==NULL && root->right==NULL)
            ans.push_back(root->val);
        inorder(root->right,ans);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1,r2;
        inorder(root1,r1);
        inorder(root2,r2);
        if(r1.size()!=r2.size())
            return false;
        for(int i=0;i<r1.size();i++){
            if(r1[i]!=r2[i])
                return false;
        }
        return true;
    }
};