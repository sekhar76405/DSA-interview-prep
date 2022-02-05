/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
*/

// Easy approach O(N)
// take two node prev and curr. keep deleting curr until prev != curr else move forward
// so in a linear way check prev = curr, if yes delete that curr and compare prev and new curr in next loop

ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    ListNode* prev_node = head;     //first node
    ListNode* curr_node = head->next;      //second node
    
    while(curr_node != NULL){       //until we reach the end or prev is last node
        if(prev_node->val == curr_node->val){   //if same
            prev_node->next = curr_node->next;  // link the prev to next of curr i.e deleting curr
            curr_node = curr_node->next;    //moving curr to its next node
        }
        else{       // else keep moving forward
            prev_node = curr_node;  
            curr_node = curr_node->next;
        }
    }
    return head;
}