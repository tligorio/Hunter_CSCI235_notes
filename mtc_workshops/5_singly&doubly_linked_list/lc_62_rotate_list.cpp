#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
     
};



ListNode* rotateRight(ListNode* head, int k){

        //MAIN IDEA: traverse the list to count the number of nodes and 
        // connect tail to head (circularly-linked list), 
        // then traverse again length-k nodes from the head, make this the new head and disconnect previous

        // special cases: emtpy or single-node list or k=0 -  nothing to rotate
        if(head == nullptr or head->next == nullptr or k==0)
            return head;

        ListNode* iter = head; // pointer that will traverse the list
       
       //traverse the list until last node
       //and compute the length as you go
       int length = 1;
       while(iter->next != nullptr)
       {
            iter = iter->next;
            length ++;
       }
            
        //iter now points to the last node in the list
        //connect it to the head to create a loop
        iter->next = head;
        //traverse another length-k nodes to reach the new "tail" node
        //compute k as k%length in case k>length
        k = k%length;
        for(int i = 0; i < (length-k); i++)
            iter = iter->next;
        
        //let the node after the new "tail" be the new "head"
        head = iter->next;

        //disconnect the new "tail"  from the new "head"
        iter->next = nullptr;

        return head; 
        
}


int main()
{
    // [1,2,3,4,5]
    ListNode* l1 = new ListNode(1);

    ListNode* temp1 = l1;
    ListNode* next = new ListNode(2);
    temp1->next = next;
    temp1 = next;

    next = new ListNode(3);
    temp1->next = next;
    ListNode* curr = l1;
    temp1 = next;

    // next = new ListNode(4);
    // temp1->next = next;
    // curr = l1;
    // temp1 = next;

    // next = new ListNode(5);
    // temp1->next = next;
    // curr = l1;
    // temp1 = next;

    // next = new ListNode(6);
    // temp1->next = next;
    // curr = l1;
    // temp1 = next;

    //  next = new ListNode(7);
    // temp1->next = next;
    // curr = l1;
    // temp1 = next;

    while(curr != nullptr)
    {   
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
    std::cout <<  std::endl;
   

    ListNode* rotated_l1 = rotateRight(l1, 4);
   
    curr = rotated_l1;
    while(curr != nullptr)
    {   
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
    
   
}
