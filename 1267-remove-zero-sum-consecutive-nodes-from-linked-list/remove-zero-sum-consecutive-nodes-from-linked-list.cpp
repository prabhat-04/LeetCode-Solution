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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head==NULL) return NULL;
        unordered_map<int,ListNode*> mp;
        int sum=0;
        ListNode*curr=head;
        while(curr!=NULL){
            sum+=curr->val;
            if(sum==0){
                head=curr->next;
                mp.clear();
            }
            else if(mp.find(sum)!=mp.end()){
                ListNode *temp = mp[sum]->next;
                int tt = sum+temp->val;
                while(temp!=curr){
                    mp.erase(tt);
                    temp=temp->next;
                    tt+=temp->val;
                }
                mp[sum]->next=curr->next;

            }
            else
                mp[sum]=curr;
            curr=curr->next;
        }
        return head;
    }
};