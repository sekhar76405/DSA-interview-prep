/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

// easy stack approach O(N) + O(N)
// use a stack and fill it with one traversal thorough list, in the next traversal update node values by poping the stack everytime.

ListNode* reverseList(ListNode* head) {
        ListNode *temp = head;
        stack<int> s;
        while(temp != NULL){
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            temp->val = s.top();
            //if(!stack.empty())
                s.pop();
            temp = temp->next;
        }
        return head;
}


// easy recursive approach O(N) + O(N)(recursion stack)
// write edgecases first, let recursion reverse the list from 2nd node, save the address of reversed list in new_head
// Now just iterate from new_head till end and place 1st node that head is pointing and make its next null return new_head; 
ListNode* reverseList(ListNode* head) {
        if(head == NULL)    // no node
            return head;
        if(head->next == NULL)  //single node
            return head;
        
        ListNode* new_head = reverseList(head->next);
        ListNode* temp = new_head;
        
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = head;
        head->next = NULL;
        head = new_head;
        return head;
 }

