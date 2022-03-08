    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL) return NULL;
        
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        
            if(slow == fast) break;
        }
        
        if(slow != fast) return NULL;
        
        slow = head;
        fast = fast;
        
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return fast; //Or slow any of these
    }
