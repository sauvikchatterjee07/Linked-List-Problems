    ListNode* insertionSortList(ListNode* head) {
        for(auto i = head; i; i = i->next){
            for(auto j = head; j<i; j = j->next){
                if(j->val > i->val)
                    swap(j->val, i->val);
            }
        }
        return head;
    }
