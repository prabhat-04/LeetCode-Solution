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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(auto &x:nums)
            st.insert(x);
        ListNode *ptr = head,*prev=NULL;
        while(ptr){
            if(st.find(ptr->val)!=st.end()){
                ListNode *temp = ptr;
                if(!prev){
                    head = ptr->next;
                    ptr = ptr->next;
                }
                else{
                    prev->next = ptr->next;
                    ptr=ptr->next;
                }
                delete temp;
            }
            else{
                prev=ptr;
                ptr=ptr->next;
            }
            
        }
        return head;
    }
};