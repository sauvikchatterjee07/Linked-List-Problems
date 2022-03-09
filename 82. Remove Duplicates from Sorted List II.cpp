    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *dummy = new ListNode(-1);
        ListNode *itr = dummy;
        itr->next = head; //Potential unique element;
        ListNode *curr = head->next;
        
        
        while(curr!= NULL){
            bool enteredInTheLoop = false;
            while(curr!= NULL && itr->next->val == curr->val){
                enteredInTheLoop = true;
                curr = curr->next;
            }
            
            if(enteredInTheLoop == true) itr->next = curr; //Now let curr be the potential unique element
            else itr = itr->next;
            
            if(curr!= NULL) curr = curr->next; //Dry run 1->1->1->1->1
        }
        return dummy->next;
    }
