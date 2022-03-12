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
    
private:
    void copyList(Node* head){
        
        Node* curr = head;
        
        while(curr){
            
            Node* forw = curr->next;
            Node* copy = new Node(curr->val);
            curr->next = copy;
            copy->next = forw;
            
            curr = forw;
        }
    }
    
    void copyRandomPointers(Node* head){
        Node* curr = head;
        while(curr){
            Node *curr_cp = curr->next;
            Node* random = curr->random;
            if(random != NULL)
                curr_cp -> random = random->next;
            
            curr = curr_cp->next;
        }
    }
    
    Node* extractNodes(Node* head){
        
        Node* original = head;
        Node* copy = head->next;
        Node* currentNode = copy;
        
        while(original && copy)
        {
            original->next = (original->next != NULL) ? original->next->next : original->next;
            copy->next = (copy->next != NULL) ? copy->next->next : copy->next;
            
            original = original->next;
            copy = copy->next;
        }
        return currentNode;
    }
    
public:
    Node* copyRandomList(Node* head) {
        
        if (head == NULL)
            return NULL;
        
        copyList(head);
        copyRandomPointers(head);
        return extractNodes(head);
    }
};
