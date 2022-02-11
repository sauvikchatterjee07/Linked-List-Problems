    ListNode* middleNode(ListNode* head) {
        ListNode* hare = head;
        ListNode* tortoise = head;
        while(hare && hare->next){
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        
        return tortoise;
    }
