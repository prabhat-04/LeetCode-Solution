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
    void dfs(TreeNode *leftChild,TreeNode* rightChild,int level){
        if(leftChild==NULL || rightChild==NULL) return;
        if(level%2==0) swap(leftChild->val,rightChild->val);
        dfs(leftChild->left,rightChild->right,level+1);
        dfs(leftChild->right,rightChild->left,level+1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        dfs(root->left,root->right,0);
        return root;
    }
};