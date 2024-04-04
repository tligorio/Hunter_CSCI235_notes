#include <iostream>


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


void deleteNode(ListNode* node) {

        //MAIN IDEA: we have a pointer to the node we want to delete
        // we don't have a pointer to the first node
        // we can't look back, only forward (singly-linked-list)
        // Solution: copy next element into current node and connect current to next->next

        //copy next value into current node
        node->val = node->next->val;

        //obtain a pointer to next->next
        ListNode* next = node->next->next;

        //link node to next->next
        node->next = next;
        
    }


int main()
{
    // [4,5,1,9]
    ListNode* first = new ListNode(4);

    ListNode* list = first;
    ListNode* next = new ListNode(5);
    list->next = next;
    list = next;
    ListNode* remove = list;

    next = new ListNode(1);
    list->next = next;
    list = next;

    next = new ListNode(9);
    list->next = next;
    

    deleteNode(remove);
   
    ListNode* curr = first;
    while(curr != nullptr)
    {   
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
    
   
}
