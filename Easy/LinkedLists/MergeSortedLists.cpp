/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by mixing/combining together the nodes of the first two lists.

Return the head of the merged linked list.
*/

// Easy Approach 
// there are 3 cases
// 1. if both lists are null, then return null
// 2. if any one list is null, then return the given head of other list
// 3. if both have node:
//      a. compare data of two nodes, and push the min data into new list
//      b. increment in that list whose min data has been pushed
//      c. do this untill one of the heads reach NULL;
//      d. now just see which is null, and attach flag->next with other head and return ans;

ListNode* push(int val){
    ListNode* new_node = new ListNode(val);
    return new_node;
}
    
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* ans = NULL;   // ans will be the head of new merged list 
    ListNode* flag = NULL;  // flag will point to the end of this new list, so that insertion can be O(1)
                    
    if(list1 == NULL && list2 == NULL)  //CASE 1
        return ans;
    if(list1 == NULL){      //CASE 2
        return list2;
    }
    if(list2 ==  NULL){
        return list1;
    }
    
    // comparing the first nodes to set ans and flag because in loop only flag will be moving
    if(list1->val <= list2->val){ 
        ans = push(list1->val);
        flag = ans;
        list1 = list1->next;
        
    }
    else{
        ans = push(list2->val);
        flag = ans;
        list2 = list2->next;
    }
    
    
    while(list1 != NULL && list2 != NULL){
        if(list1->val <= list2->val){   //CASE 3.a
            flag->next = push(list1->val);  //CASE 3.a
            flag = flag->next;      //increase flag
            list1 = list1->next;        //CASE 3.b
        }
        else{
            flag->next = push(list2->val);
            flag = flag->next;
            list2 = list2->next;
        }
    }
    
    if(list1 == NULL){      //CASE 3.d
        flag->next = list2;
    }
    else{
        flag->next = list1;
    }
    
    return ans;
}