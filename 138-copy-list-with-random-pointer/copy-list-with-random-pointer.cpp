/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        // Node *ptr=head;
        // while(ptr!=NULL){
        //     Node *newNode = new Node(ptr->val);
        //     newNode->next = ptr->next;
        //     ptr->next = newNode;
        //     ptr=ptr->next->next;
        // }
        // ptr=head;
        // while(ptr!=NULL){
        //     ptr->next->random = ptr->random?ptr->random->next:NULL;
        //     ptr=ptr->next->next;
        // }
        // Node *ans = head->next,*temp=head->next;
        // ptr=head;
        // while(ptr && temp){
        //     ptr->next = ptr->next?ptr->next->next:NULL;
        //     temp->next = temp->next?temp->next->next:NULL;
        //     ptr=ptr->next;
        //     temp=temp->next;
        // }
        // return ans;
        unordered_map<Node*,Node*> mp;
        Node *ans = new Node(head->val);
        mp[head] = ans;
        Node *ptr=head->next,*curr=ans;
        while(ptr!=NULL){
            Node * newNode = new Node(ptr->val);
            mp[ptr] = newNode;
            curr->next = newNode;
            ptr=ptr->next;
            curr = curr->next;
        }

        ptr=head;
        while(ptr!=NULL){
            if(ptr->random){
                mp[ptr]->random = mp[ptr->random];
            }
            ptr=ptr->next;
        }
        return ans;
    }
};