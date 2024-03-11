/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
Node* helper(Node* head){
    if(head==nullptr) return nullptr;
    Node *curr = head;
    while(curr!=nullptr){
        if(curr->child!=NULL){
            Node *temp = curr->next;
            Node *tail = helper(curr->child);
            curr->next = curr->child;
            curr->child->prev=curr;
            // tail->next = temp;
            // temp->prev=tail;
            curr->child=nullptr;
            if (temp != nullptr){
                tail->next = temp;
                temp->prev = tail;
            }
        }
        if(curr->next==NULL) break;

        curr=curr->next;
    }
    return curr;
}

public:
    Node* flatten(Node* head) {
        if(head==NULL) return NULL;
        helper(head);
        return head;
    }
};