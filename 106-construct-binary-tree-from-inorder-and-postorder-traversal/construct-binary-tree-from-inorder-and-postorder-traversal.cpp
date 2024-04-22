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
    TreeNode *solve(vector<int> &inorder,vector<int> &postorder,unordered_map<int,int> &mp,int i,int j,int &postIndex){
        if(i>j) return NULL;
        TreeNode *node = new TreeNode(postorder[postIndex--]);
        int index = mp[node->val];
        node->right = solve(inorder,postorder,mp,index+1,j,postIndex);
        node->left = solve(inorder,postorder,mp,i,index-1,postIndex);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        int postIndex = postorder.size()-1;
        return solve(inorder,postorder,mp,0,postorder.size()-1,postIndex);
    }
};