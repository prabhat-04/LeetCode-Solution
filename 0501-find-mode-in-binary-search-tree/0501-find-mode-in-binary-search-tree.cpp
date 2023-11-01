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
    vector<int> findMode(TreeNode* root) {
        if(root==NULL)
            return{};
        unordered_map<int,int> mp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * curr = q.front();
            q.pop();
            mp[curr->val]++;
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        int freq=INT_MIN;
        for(auto it :mp){
            if(freq<it.second){
                freq=it.second;
            }
        }
        vector<int> ans;
        for(auto it:mp){
            if(it.second==freq)
                ans.push_back(it.first);
        }
        return {ans};
    }
};