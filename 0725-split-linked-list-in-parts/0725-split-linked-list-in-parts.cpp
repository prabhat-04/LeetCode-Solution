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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        vector<ListNode*> ans(k);
        temp=head;
        if(n<=k){
            int i=0;
            while(temp!=NULL){
                ans[i] = temp;
                temp=temp->next;
                ans[i]->next=NULL;
                i++;
            }
            return ans;
        }
        int rem = n % k;
        int div = n / k;
        int i=0;
        while(temp!=NULL){
            int c = div-1;
            ans[i]=temp;
            while(c--){
                temp=temp->next;
            }
            if(temp==NULL)
                return ans;
            if(rem!=0){
                temp=temp->next;
                rem--;
            }
            ListNode* temp2 = temp;
            temp = temp->next;
            temp2->next=NULL;
            i++;
        }
        return ans;
    }
};