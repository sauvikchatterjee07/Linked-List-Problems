    int pairSum(ListNode* head) {
        ListNode *hr = head;
        ListNode *tor = head;
        int maxVal = 0;
        while(hr && hr->next){
            tor = tor->next;
            hr = hr->next->next;
        }
        
        ListNode * nextnode, *prev = NULL;
        while(tor){
            nextnode = tor->next;
            tor->next = prev;
            prev = tor;
            tor = nextnode;
        }
        while(prev){
            maxVal = max(maxVal, head -> val + prev -> val);
            prev = prev -> next;
            head = head -> next;
        }
        return maxVal;          
    }
