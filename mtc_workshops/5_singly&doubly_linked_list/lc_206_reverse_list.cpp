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



ListNode* reverseList(ListNode* head){

        //MAIN IDEA: flip the next pointer of each node while advancing the head towards the tail
        //to do so, you must traverse the list with three pointers: previous, head and next.
        // each time you advance the head, make head-next point to previous then move each pointer over by one 
      

        //special case: no nodes to revese
        if(head == nullptr)
            return head;


        ListNode* previous = nullptr; //a pointer to the node we want to reverse the next pointer to
        ListNode* next = head->next; //a pointer to the node after the head before reversal of head->next

        while(next != nullptr)
        {
            head->next = previous;
            previous = head;
            head = next;
            next = next->next;
        }
        head->next = previous;
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

    next = new ListNode(4);
    temp1->next = next;
    curr = l1;
    temp1 = next;

    next = new ListNode(5);
    temp1->next = next;
    curr = l1;
    temp1 = next;

    next = new ListNode(6);
    temp1->next = next;
    curr = l1;
    temp1 = next;

     next = new ListNode(7);
    temp1->next = next;
    curr = l1;
    temp1 = next;

    while(curr != nullptr)
    {   
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
    std::cout <<  std::endl;
   

    ListNode* rotated_l1 = reverseList(l1);
   
    curr = rotated_l1;
    while(curr != nullptr)
    {   
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
    
   
}
