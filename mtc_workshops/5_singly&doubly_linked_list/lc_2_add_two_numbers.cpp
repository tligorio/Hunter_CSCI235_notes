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



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){

        //MAIN IDEA: since the numbers are stored in reverse order, first node is least-significant digit
        // start from the beginning of the two lists 
        // add values in the nodes (or 0 if a node is nullptr) + carry
        // compute the digit value as sum%10
        // compute carry as sum/10 (integer division)


        int sum = 0, carry = 0, val1 = 0, val2 = 0;
        ListNode* sum_list = new ListNode(0); //first node created outside the sum loop will be discarded (no leading zeros)
        ListNode* sum_iterator = sum_list; // pointer that will iterate the sum_list
       
       while(l1!=nullptr or l2!=nullptr or carry > 0) //if carry > 0 after adding all digits, add another node
        {
            //if a node becomes nullptr, add 0 instead
            val1 = (l1!=nullptr) ? l1->val : 0;
            val2 = (l2!=nullptr) ? l2->val : 0;
            sum = val1 + val2 + carry;
            

            carry = sum/10;
            sum = sum%10;

            //instantiate node with sum and add to list
            ListNode* temp = new ListNode(sum);
            sum_iterator->next = temp;

            //advance the pointers
            sum_iterator = sum_iterator->next;//advance the sum pointer
            if(l1 != nullptr)
                l1 = l1->next;
            if(l2 != nullptr)
                l2 = l2->next;
  
        }

        return sum_list->next; //->next because first node was instantiated outside of the sum loop
        
}


int main()
{
    // [2,4,3]
    ListNode* l1 = new ListNode(2);

    ListNode* temp1 = l1;
    ListNode* next = new ListNode(4);
    temp1->next = next;
    temp1 = next;

    next = new ListNode(3);
    temp1->next = next;
    ListNode* curr = l1;

    while(curr != nullptr)
    {   
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
    std::cout <<  std::endl;
   


    // [5,6,6,9]
    ListNode* l2 = new ListNode(5);

    ListNode* temp2 = l2;
    ListNode* next2 = new ListNode(6);
    temp2->next = next2;
    temp2 = next2;

    next2 = new ListNode(6);
    temp2->next = next2;
    temp2 = next2;

    next2 = new ListNode(9);
    temp2->next = next2;
    

    curr = l2;
    while(curr != nullptr)
    {   
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
    std::cout <<  std::endl;
    
    ListNode* sum = addTwoNumbers(l1, l2);
   
    curr = sum;
    while(curr != nullptr)
    {   
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
    
   
}
