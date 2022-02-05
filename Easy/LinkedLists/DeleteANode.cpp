/*
Write a function to delete a node in a singly-linked list. 
You will not be given access to the head of the list,
instead you will be given access to the node to be deleted directly.

It is guaranteed that the node to be deleted is not a tail node in the list.
*/

// Easy Approach O(1)
// copy the data from the next node in curr node and remove the link to next node and join it with the next of next node

void deleteNode(ListNode* node) {
    if(node->next->next == NULL){
        node->val = node->next->val;
        node->next = NULL;
        return ;
    }
    node->val = node->next->val;
    node->next = node->next->next;       
}