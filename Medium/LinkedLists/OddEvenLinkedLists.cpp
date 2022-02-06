/*
Given the head of a singly linked list, group all the nodes with odd indices together 
followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.
*/


// Medium Approach O(N)
// keep linking all odds one by one, and evens one by one in one scan from left to right
// then finally attach last odd with first even
// see this image for ref: https://assets.leetcode.com/users/images/a4660d6c-12b9-4ef8-a3a3-a2d8614f8e8b_1638408122.6492355.png

ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    ListNode* odd = head,*even= head->next;
    ListNode* flag = head->next;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    if(even==NULL)
        odd->next = flag;
    else{
        odd->next = flag;
        even->next = NULL;
    }
    
    return head;
}
