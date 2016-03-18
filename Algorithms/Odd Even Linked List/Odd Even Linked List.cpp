/**
    Description: Odd Even Linked List
    Author:Shelldream
    Date:2016-03-18
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* create_list(vector<int> nums)
{
    ListNode* head=NULL;
    ListNode* tail=NULL;
    for(int i = 0;i<nums.size();i++)
    {
        ListNode* p = new ListNode(nums[i]);
        if(head==NULL)
        {
            head=p;
            tail=p;
        }
        else
        {
            tail->next = p;
            tail = tail->next;
        }
    }
    return head;
}

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd_tail = NULL;
        ListNode* even_tail = NULL;
        ListNode* current_tail = head;
        ListNode* even_head = NULL;
        int count = 1;
        while(current_tail != NULL)
        {
            if(count % 2 != 0)
            {
                if(odd_tail != NULL)
                {
                    odd_tail->next = current_tail;
                }
                odd_tail = current_tail;
            }
            else
            {
                if(even_tail != NULL)
                {
                    even_tail->next = current_tail;
                }
                else even_head = current_tail;
                even_tail = current_tail;
            }
            current_tail = current_tail->next;
            count++;
        }
        if(odd_tail != NULL)
            odd_tail->next = even_head;
        if(even_tail)
            even_tail->next = NULL;
        return head;
    }
};

int main()
{
    int data[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode *L = create_list(nums);
    Solution test;
    ListNode* head = test.oddEvenList(L);
    while(head)
    {
        cout<<head->val<<endl;
        head = head->next;
    }
}

