class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = &dummy;
        ListNode* second = &dummy;
        
        // Advance 'first' so there's a gap of n between first and second
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        
        // Move both until 'first' hits the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Delete node
        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp; 
        
        return dummy.next;
    }
};