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
    int solve(TreeNode *root,unordered_map<int,int> &mp,int &maxFreq){
        if(!root) return 0;
        auto l = solve(root->left,mp,maxFreq);
        auto r = solve(root->right,mp,maxFreq);
        int temp = l+r+root->val;
        mp[temp]++;
        if(mp[temp]>maxFreq) maxFreq = mp[temp];
        return temp;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        int maxFreq = INT_MIN;
        solve(root,mp,maxFreq);
        vector<int> ans;
        for(auto it:mp){
            if(it.second==maxFreq) ans.push_back(it.first);
        }
        return ans;
    }
};