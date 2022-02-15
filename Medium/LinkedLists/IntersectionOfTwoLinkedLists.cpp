/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.
*/

// Easy Approach O(N*N)
// For each node in List 1, travel whole List 2, return where temp1 == temp2 

// Easy Approach O(N) + O(N)
// Traverse List1 and store addresses in Hash map, traverse list 2, return if adress already exists.


// Medium Approach O(N)
// The idea is to equalise lenghts, and compare 2 nodes at a time.
// 2 Approaches for equalise lenghts: -

// A. calc lenghts of l1, l2.. take diff of them.. 
// and move that diff in the longer list so that we start at equal distances in both lists. 
// Now start seeing if temp1 == temp2 else move forward
// if both reach null, then no intersection, else return that address

// B. Travel both lists simultaneously at each time, the shorter list will reach null first
// now when one ptr reaches null first, then point it to the head of its opp list, and continue 
// now the other ptr reaches null second, then point it to the head of its opp list,
// what this does is make the two ptrs at equal lenght.. basically we are removing the extra lenght from the longer list.
// now that the lenghts are equal
// Now start seeing if temp1 == temp2 else move forward
// if both reach null, then no intersection, else return that address

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
    if(headA == NULL || headB == NULL)
        return NULL;
    
    ListNode *t1 = headA, *t2 = headB;  //initially t1 points A, t2 points B
    
    
    while(t1!=t2){
        
        t1 = t1->next;
        t2 = t2->next; 
        
        if(t1 == NULL && t2 == NULL)        // if they both reach null, then there is no intersection
            break;
        if(t1 == NULL)  
            t1 = headB;
        if(t2 == NULL)
            t2 = headA;
    }
    
    return t1; 

    
}