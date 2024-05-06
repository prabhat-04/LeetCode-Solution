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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode *curr=head;
        while(curr){
            while(!st.empty() && st.top()->val<curr->val){
                ListNode *temp=st.top();
                st.pop();
                delete temp;
            }
            st.push(curr);
            curr=curr->next;
        }
        if(st.empty()) return NULL;
        head=st.top();
        st.pop();
        head->next=NULL;
        while(!st.empty()){
            st.top()->next=head;
            head=st.top();
            st.pop();
        }
        return head;
    }
};