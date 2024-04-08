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
    TreeNode* successor(TreeNode *root){
        if(!root->left) return root;
        return successor(root->left);
    }

    TreeNode* precedor(TreeNode *root){
        if(!root->right) return root;
        return precedor(root->right);
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(key < root->val)
            root->left = deleteNode(root->left,key);
        else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }
        else if(root->val==key){
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            else if(!root->right){
                TreeNode *temp = precedor(root->left);
                root->val = temp -> val;
                root -> left = deleteNode(root->left,temp->val);
            }
            else{
                TreeNode *temp = successor(root->right);
                root->val = temp->val;
                root -> right = deleteNode(root->right,temp->val);
            }
        }
        return root;
    }
};