/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private: ListNode* mergetwoLL(ListNode* l1, ListNode* l2){
    if(l1 == NULL || l2 == NULL) return l1 != NULL ? l1 : l2;
    ListNode* dummy = new ListNode(-1);
    ListNode* prev = dummy;
    ListNode* c1 = l1;
    ListNode* c2 = l2;
    while(c1 != NULL && c2 != NULL){
        if(c1->val < c2->val){
            prev->next = c1;
            c1 = c1->next;
        }
        else{
            prev->next = c2;
            c2 = c2->next;
        }
        prev = prev->next;
    }
    prev->next = c1 != NULL ? c1 : c2;
    
    return dummy->next;
}
    ListNode* mergeKList(vector<ListNode*>& lists, int si, int ei){
        if(si>ei) return NULL;
        if(si == ei) return lists[ei];
        int mid = (si + ei)/2;
        
        ListNode* l1 = mergeKList(lists, si, mid);
        ListNode* l2 = mergeKList(lists, mid+1, ei);
        
        return mergetwoLL(l1, l2);
    }
    
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return mergeKList(lists, 0, lists.size()-1);
    }
};
