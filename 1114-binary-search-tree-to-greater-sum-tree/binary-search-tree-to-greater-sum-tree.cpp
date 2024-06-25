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
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        preorder(root,sum);
        return root;
    }

    void preorder(TreeNode *root,int &sum){
        if(!root) return ;
        preorder(root->right,sum);
        int temp = root->val;
        root->val+=sum;
        sum+=temp;
        preorder(root->left,sum);

    }
};