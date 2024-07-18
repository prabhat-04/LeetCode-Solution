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
    void postorder(TreeNode *root,vector<TreeNode*> &ans,unordered_set<int> &s,TreeNode* par, bool isLeft ){
        if(!root) return;
        postorder(root->left,ans,s,root,true);
        postorder(root->right,ans,s,root,false);
        if(s.find(root->val)!=s.end()){
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            if(par){
                if(isLeft)
                    par->left = NULL;
                else
                    par->right = NULL;
            }
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s;
        for(auto it:to_delete){
            s.insert(it);
        }
        vector<TreeNode*>ans;
        if(s.find(root->val)==s.end()){
            ans.push_back(root);
           
        }
         postorder(root,ans,s,NULL,true);
        // else{
        //     ans.push_back(root->left);
        //     ans.push_back(root->right);
        //     postorder(root->left,ans,s,root,true);
        //     postorder(root->right,ans,s,root,false);
        // }
        return ans;

    }
};