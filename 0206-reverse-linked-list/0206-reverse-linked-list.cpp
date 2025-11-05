class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 'prev' will eventually be the new head.
        // It starts as null because the new "end" of the list
        // (the original head) must point to null.
        ListNode* prev = nullptr;
        
        // 'curr' is our iterator, starting at the beginning.
        ListNode* curr = head;
        
        // We loop as long as we have a node to process
        while (curr != nullptr) {
            // 1. Store the *next* node before we break the link
            ListNode* nextTemp = curr->next;
            
            // 2. REVERSE the link:
            //    Point the current node's 'next' pointer backward to 'prev'.
            curr->next = prev;
            
            // 3. Move our pointers one step forward for the next iteration:
            //    The 'prev' node for the *next* loop is our 'curr' node.
            prev = curr;
            //    The 'curr' node for the *next* loop is the 'nextTemp' we saved.
            curr = nextTemp;
        }
        
        // When the loop ends (curr is null), 'prev' is
        // at the last node of the original list, which is
        // the new head of the reversed list.
        return prev;
    }
};