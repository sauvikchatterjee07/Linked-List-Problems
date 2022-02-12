    void reorderList(ListNode* head) {
       if(head == NULL || head->next == NULL) return;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;

        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode *l1 = head;
        ListNode *l2 = reverse(slow);
        merge(l1, l2);    
    }
    
    private:
    
    ListNode* reverse(ListNode *l2){
        if(l2 == NULL) return NULL;
        
        ListNode *prev = NULL;
        ListNode *curr = l2;
        ListNode *next = l2->next;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void merge(ListNode *l1, ListNode *l2) {
        while (l2 != NULL) {
            ListNode *next = l1->next;
            l1->next = l2;
            l1 = l2;
            l2 = next;
        }
    } 
