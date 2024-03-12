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
                ListNode *temp=curr,*y=head;
                curr=curr->next;
                temp->next=NULL;
                // while(y!=NULL){
                //     ListNode *x = y;
                //     cout<<x->val<<endl;
                //     y=y->next;
                //     delete x;
                // }
                head=curr;
                mp.clear();
                continue;
            }
            else if(mp.find(sum)!=mp.end()){
                ListNode *temp = mp[sum]->next;
                int tt = sum+temp->val;
                while(temp!=curr){
                    mp.erase(tt);
                    ListNode *x=temp;
                    temp=temp->next;
                    tt+=temp->val;
                    delete x;
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