#include <iostream>


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    //MAIN IDEA: iteratively compare first noe in list1 and list2  and insert smallest in merged list

    // Check for empty list
    if(list1 == nullptr)
        return list2;
    else if(list2 == nullptr)
        return list1;

    // First need to attach the first node
    ListNode* merged = nullptr;
    if(list1->val <= list2->val)
    {
        merged = list1;       // make first node in list1 first node in merged
        list1 = list1->next;  // advance list1
    }else{
        merged = list2;        // make first node in list2 first node in merged
        list2 = list2->next;   //advance list2
    }
        

    //setup an iterator to advance in merged list
    ListNode* merged_it = merged; 

    while((list1 != nullptr) and list2 != nullptr)
    {
        //case list1 smaller
        if(list1->val < list2->val)
        {
            merged_it->next = list1;    //attach list1 to merged list
            list1 = list1->next;        //advance list1
            merged_it = merged_it->next; //advance merged iterator
        }else{
            merged_it->next = list2;    //attach list2 to merged list
            list2 = list2->next;        //advance list2
            merged_it = merged_it->next; //advance merged iterator
        }
            
    }

    //check if there are remaining nodes in one of the two lists and append to merged list
    if(list1 != nullptr)
        merged_it->next = list1;
    else
        merged_it->next = list2;

    return merged;
        
}




int main()
{
    // [1,2,4]
    //first node
    ListNode* list1 = new ListNode(1);
    ListNode* curr1 = list1;

    //second node
    ListNode* next1 = new ListNode(2);
    list1->next = next1;
    curr1 = next1;

    //third node
    next1 = new ListNode(4);
    curr1->next = next1;


    // [1,3,4]
    //first node
    ListNode* list2 = new ListNode(1);
    ListNode* curr2 = list2;

    //second node
    ListNode* next2 = new ListNode(3);
    list2->next = next2;
    curr2 = next2;

    //third node
    next2 = new ListNode(4);
    curr2->next = next2;
    list1 = nullptr;
    list2 = nullptr;



    // //merged list
    ListNode* merged = mergeTwoLists(list1, list2);
    

    // //print merged
    while(merged != nullptr)
    {   
        std::cout << merged->val << std::endl;
        merged = merged->next;
    }
    
   
}
