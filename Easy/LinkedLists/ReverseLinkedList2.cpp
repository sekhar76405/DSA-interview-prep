/*
Given the head of a singly linked list and two integers left and right where left <= right, 
reverse the nodes of the list from position left to position right, and return the reversed list.
*/

// easy Approach O(N)
// cut from front and end, reverse the mid part and join the links again
// only edge case is if we have to reverse from start index as there will be no node before it, so no front part.

ListNode* reverse(ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;
    ListNode* prev=NULL;
    ListNode* cur=head;
    ListNode* n;
    while(cur!=NULL){
        n=cur->next;
        cur->next=prev;
        prev=cur;
        cur=n;
    }
    return prev;
}
    
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* temp = head;
    int count = 1;
    while(count++<left-1)   //traverse till one node before left
        temp = temp->next;
    ListNode* front = temp; //save that front node
    count--;    
    while(count++<right)    //traverse till right node
        temp = temp->next;
    
    ListNode* end = temp->next;     //save the node after the right node
    temp->next = NULL;      //no cut the link of right----end with right----NULL
    
    if(left == 1){      //if we have reverse from begining, there will be no front node, thus head will be from the start of the reversed list
        head = reverse(front);
    }
    else
        front->next = reverse(front->next);     //sending the node next to front to start reversing and linking back front with new_head returned by reverse()
    
    temp = head;    // now travel till the end of reversed list to join that with end
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = end;   //joined
    return head;
    
}