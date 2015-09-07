/*
	Remove Linked List Elements
	Author:Xiaojun Huang
	Date:2015-09-07
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

void print_list(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<"  ";
        head = head->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return NULL;
        ListNode* p = head;
        while(p->next)
        {
            if(p->next->val == val)
            {
                ListNode* tmp = p->next;
                p->next = p->next->next;
                delete tmp;
            }
            else p = p->next;
        }
        if(head->val == val)
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        return head;
    }
};


int main()
{
    int data[] = {1,1,1,2,3,1,1,4,5};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode* L1 = create_list(nums);
    Solution test;
    ListNode* L2 = test.removeElements(L1,1);
    print_list(L2);
}
