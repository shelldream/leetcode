/*
    Description: 
        Add Two Numbers
        https://leetcode.com/problems/add-two-numbers/description/
    Author: shelldream
    Date: 2017-10-15
*/

#include <iostream>
#include <string>
#include <vector>
#include "../../common/LinkedList.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL;
        ListNode* tail = NULL;
        int carry_bit = 0;
        
        while(l1 && l2)
        {
            int sum = l1->val + l2->val + carry_bit;
            carry_bit = sum/10;
            int val = sum % 10;
            if (NULL == ans)
            {
                ans = new ListNode(val);
                tail = ans;
            }
            else
            {
                ListNode* tmp = new ListNode(val);
                tail->next = tmp;
                tail = tmp;
            }

            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1)
        {
            int sum = l1->val + carry_bit;
            carry_bit = sum/10;
            int val = sum % 10;
            if (NULL == ans)
            {
                ans = new ListNode(val);
                tail = ans;
            }
            else
            {
                ListNode* tmp = new ListNode(val);
                tail->next = tmp;
                tail = tmp;
            }

            l1 = l1->next;
        }

        while(l2)
        {
            int sum = l2->val + carry_bit;
            carry_bit = sum/10;
            int val = sum % 10;
            if (NULL == ans)
            {
                ans = new ListNode(val);
                tail = ans;
            }
            else
            {
                ListNode* tmp = new ListNode(val);
                tail->next = tmp;
                tail = tmp;
            }

            l2 = l2->next;
        }
        
        if (carry_bit > 0)
        {
            ListNode* tmp = new ListNode(carry_bit);
            tail->next = tmp;
            tail = tmp;    
        }

        return ans;
    }
};


int main()
{
    Solution solution;
    
    //test case1 
    {
        int data1[] = {2, 4, 3};
        int size1 = sizeof(data1)/sizeof(int);
        int data2[] = {5,6,4};
        int size2 = sizeof(data2)/sizeof(int);

        SingleLinkedList L1(data1, size1); 
        SingleLinkedList L2(data2, size2);
        L1.printList();
        L2.printList();
        ListNode* l1 = L1.getHead();
        ListNode* l2 = L2.getHead();
        SingleLinkedList ans(solution.addTwoNumbers(l1, l2));
        ans.printList();
    }

    cout << endl;
    
    //test case2 
    {
        int data1[] = {2, 4, 5};
        int size1 = sizeof(data1)/sizeof(int);
        int data2[] = {5,6,4};
        int size2 = sizeof(data2)/sizeof(int);

        SingleLinkedList L1(data1, size1); 
        SingleLinkedList L2(data2, size2);
        L1.printList();
        L2.printList();
        ListNode* l1 = L1.getHead();
        ListNode* l2 = L2.getHead();
        SingleLinkedList ans(solution.addTwoNumbers(l1, l2));
        ans.printList();
    }

}
