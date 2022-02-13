ListNode* swapNodes(ListNode* head, int k) {
        
        int cnt = 1, val = k;
        for(auto i = head; i; i= i->next)
            cnt ++;
            
        int end = cnt - val;
        ListNode *l1 = head;
        while(end > 1 && l1->next){
            l1 = l1->next;
            end--;
        }
        
        
        ListNode *l2 = head;
        
        while(k>1){
            l2 = l2->next;
            k--;
        }
        swap(l1->val, l2->val);
        return head;
        
    }
