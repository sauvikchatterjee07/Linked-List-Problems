    ListNode* sortList(ListNode* head) {
        ListNode* cur = head;
        
        while(cur){
            ListNode* iter = cur;
            ListNode* min = iter;
            while(iter){         // Finding the min value of the right side
                if(iter->val < min->val){
                    min = iter;
                }
                iter = iter->next;
            }
            swap(cur->val, min->val); //swap it with the current value
            cur = cur->next;
        }
        return head;
    }
