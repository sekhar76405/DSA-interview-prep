// Given the head of a singly linked list, return the pointer to middle node of the linked list.

// If there are two middle nodes, return the second middle node.

// easy approach O(N)
// find size of the list and traverse untill count =0 to size/2-1, return the next of that node

ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        while(temp!= NULL){
            size++;
            temp = temp->next;
        }
        if(size%2!=0){
            temp = head;
            int count = 0;
                
            while(count < size/2){
                temp = temp->next;
                count++;
            }
            return temp;
        }
        else{
            temp = head;
            int count = 0;
                
            while(count < size/2){
                temp = temp->next;
                count++;
            }
            return temp;
        }
    }