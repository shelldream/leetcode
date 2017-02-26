/**
 *  Description:
 *      Algorithm61 Rotate List 
 *      https://leetcode.com/problems/rotate-list/
 *  Author: shelldream
 *  Date: 2017-02-24
 */

#include <iostream>
#include "../../common/basic.h"

using std::cout;
using std::endl;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (NULL == head)
            return head;
        
        int list_len = 0;
        ListNode *tmp = head;
        while (tmp != NULL)
        {
            ++list_len;
            tmp = tmp->next;
        }
        k %= list_len;
        if (0 == k)
            return head;

        ListNode *fast = head;
        int count = 0;
        while (fast != NULL && count < k)
        {
            fast = fast->next;
            ++count;
        }

        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        
        return head;
    }
    
};

int main()
{
    int data[] = {1,2,3,4,5};
    int n = sizeof(data)/sizeof(data[0]);
    SingleLinkedList input(data, n);
    input.printList();
    
    Solution solution;
    ListNode* new_head = solution.rotateRight(input.getHead(), 23);
    //ListNode* new_head = solution.rotateRight(input.getHead(), 2);
    //ListNode* new_head = solution.rotateRight(input.getHead(), 2);
    SingleLinkedList output(new_head);
    output.printList();
}
