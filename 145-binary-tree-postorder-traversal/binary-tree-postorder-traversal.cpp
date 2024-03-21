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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        stack<int> tt;
        st.push(root);
        while(!st.empty()){
            auto curr = st.top();
            st.pop();
            tt.push(curr->val);
            if(curr->left) st.push(curr->left);
            if(curr->right) st.push(curr->right);
        }
        while(!tt.empty()){
            ans.push_back(tt.top());
            tt.pop();
        }
        return ans;
    }
};