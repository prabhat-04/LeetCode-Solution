/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    void solve(TreeNode* root,TreeNode* p,stack<TreeNode*>&st){
        TreeNode *ptr=root;
        while(ptr!=NULL){
            st.push(ptr);
            if(ptr==p) break;
            if(p->val < ptr->val) ptr=ptr->left;
            else ptr = ptr->right;
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*>st1,st2;
        solve(root,p,st1);
        solve(root,q,st2);
        while(!st1.empty() && !st2.empty()){
            if(st1.top()==st2.top()) return st1.top();
            if(st1.size()>st2.size()) st1.pop();
            else st2.pop();
        }
        return NULL;
    }
};