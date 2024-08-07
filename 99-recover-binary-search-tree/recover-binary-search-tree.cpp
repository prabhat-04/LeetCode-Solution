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
    TreeNode* first=NULL,*last=NULL,*prev=NULL;
    void inorder(TreeNode * root){
        if(!root) return;
        inorder(root->left);
        if(prev!=NULL && root->val < prev->val){
            if(!first){
                first=prev;
                last=root;
            }
            else last = root;
        }
        prev=root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val,last->val);
    }
};