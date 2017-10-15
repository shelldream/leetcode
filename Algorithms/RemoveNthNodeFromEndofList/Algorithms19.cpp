/*
    Description: 
        Remove Nth Node From End of List
        https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
    Author: shelldream
    Date: 2017-10-15
*/

#include <iostream>
#include "../../common/LinkedList.h"

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (NULL == head)
            return NULL;

        ListNode* before = head;
        int count = 0;
        while(before && count < n)
        {
            before = before->next;
            ++count;
        }
        ListNode* after = head;
        
        while(before && before->next)
        {
            before = before->next;
            after = after->next;    
        }
        
        if (NULL == before && after == head)// delete the head node
        {
            ListNode* to_del = after;
            head = head->next;
            delete to_del;
            to_del = NULL;
            return head;
        }

        ListNode* to_del = after->next;
        after->next = after->next->next;
        delete to_del;
        to_del = NULL;

        return head;
    }
};


int main()
{
    Solution solution;
    
    #if 0
    //test case1 
    {
        int data[] = {1,2, 3, 4, 5};
        int size = sizeof(data)/sizeof(int);

        SingleLinkedList L1(data, size); 
        L1.printList();
        ListNode* head = L1.getHead();
        SingleLinkedList ans(solution.removeNthFromEnd(head, 5));
        ans.printList();
    }

    cout << endl;
    #endif

    //test case2 
    {
        int data2[] = {0, 1, 2, 3, 4, 5, 6, 7};
        int size2 = sizeof(data2)/sizeof(int);
        vector<int> ts(data2, data2+size2); 
        SingleLinkedList L2(ts); 
        L2.printList();
        ListNode* head = L2.getHead();
        SingleLinkedList ans(solution.removeNthFromEnd(head, 2));
        ans.printList();
    }

}
