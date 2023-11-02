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
    int cnt=0;
    pair<int,int> help(TreeNode* root){
        if(root==NULL)
            return{0,0};
        pair<int,int> l = help(root->left);
        pair<int,int> r = help(root->right);
        int sum =root->val+l.first+r.first;
        int size = 1+ l.second + r.second;
        if(sum/size==root->val)
            cnt++;
        return {sum,size};
    }

    int averageOfSubtree(TreeNode* root) {
        help(root);
        // cout<<sum<<" "<<size<<endl;
        return cnt;
    }
};