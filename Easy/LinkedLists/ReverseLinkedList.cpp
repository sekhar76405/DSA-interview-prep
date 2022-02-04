/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

// easy approach O(N) + O(N)
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

