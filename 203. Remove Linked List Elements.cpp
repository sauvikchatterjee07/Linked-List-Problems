    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        
        while(curr){
            if(curr->val == val){
                if(!prev) head = curr->next;
                else prev->next = curr->next;
            }
            else{
                prev = curr;
            }
            curr = curr->next;
        }
        return head;  
        }
