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
    bool isEvenOddTree(TreeNode* root) {
        int flag = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            if(flag%2==0){
                int temp = INT_MIN;
                for(int i=0;i<size;i++){
                    auto curr = q.front();
                    q.pop();
                    if(temp>=curr->val || curr->val%2!=1){
                        return false;
                    }
                    temp = curr->val;
                    if(curr->left)
                        q.push(curr->left);
                    if(curr->right)
                        q.push(curr->right);
                }
            }
            else{
                int temp = INT_MAX;
                for(int i=0;i<size;i++){
                    auto curr = q.front();
                    q.pop();
                    if(temp<=curr->val || curr->val%2!=0){
                        return false;
                    }
                    temp = curr->val;
                    if(curr->left)
                        q.push(curr->left);
                    if(curr->right)
                        q.push(curr->right);
                }

            }
            flag++;
        }
        return true;
    }
};