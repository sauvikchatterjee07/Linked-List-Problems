    bool hasCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL) return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            //slow and fast pointer can only be equal if there is a cycle in the LL
            if(slow == fast) return true;
        }
        return false;
    }
