/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
*/

// Easy 2 pointer approach O(N)
// Use slow and fast pointer that will run at 1x and 2x speed. If they both meet at a node,then there exist a loop

bool hasCycle(ListNode *head) {
    if (!head) 
        return false;
    
    ListNode *slow = head, *fast = head;
    
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) 
            return true;
    }
    
    return false;
    
}