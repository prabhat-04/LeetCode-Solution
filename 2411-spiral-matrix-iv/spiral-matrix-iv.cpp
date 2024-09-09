/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        if(!head) return ans;
        ListNode*ptr = head;
        int top=0,bottom=m-1,left=0,right=n-1;
        while(ptr){
            for(int i=left;i<=right && ptr!=NULL;i++){
                ans[top][i] = ptr->val;
                ptr = ptr->next;
            }
            top++;
            for(int i=top;i<=bottom && ptr!=NULL;i++){
                ans[i][right] = ptr->val;
                ptr = ptr->next;
            }
            right--;

            for(int i=right;i>=left && ptr!=NULL;i--){
                ans[bottom][i] = ptr->val;
                ptr = ptr->next;
            }

            bottom--;

            for(int i=bottom;i>=top && ptr!=NULL;i--){
                ans[i][left] = ptr->val;
                ptr = ptr->next;
            }
            left++;
        }
        return ans;
    }
};