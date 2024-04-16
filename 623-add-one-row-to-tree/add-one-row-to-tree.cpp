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
    void solve(TreeNode* root,int val,int curr,int depth){
        if(!root) return;
        if(curr==depth-1){
            TreeNode* l = new TreeNode(val);
            TreeNode* r = new TreeNode(val);
            auto left = root->left;
            auto right = root->right;
            l->left=left;
            r->right = right;
            root->left=l;
            root->right=r;
            return;
        }
        solve(root->left,val,curr+1,depth);
        solve(root->right,val,curr+1,depth);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode * node = new TreeNode(val);
            node->left = root;
            return node;
        }
        solve(root,val,1,depth);
        return root;
    }
};