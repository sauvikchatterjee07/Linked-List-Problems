    ListNode* rotateRight(ListNode* head, int k) {
       if(head == NULL or k == 0) return head;
        
        ListNode *tail = head;
        int len = 1;
        
        while(tail->next) //Count the length
            tail = tail->next, len++;
        
        tail->next = head; //link as a circle
        
        k = k%len;
        
        for(int i = 0; i< len - k; i++) //Iterate till before the tail node which is gonna be the new head node
            tail = tail->next;
        
        head = tail->next;
        tail->next = NULL;
        
        return head;            
    }
