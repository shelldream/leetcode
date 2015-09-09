/**
	Remove Duplicates from Sorted List
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

void print_list(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode* p = head;
        while(p->next)
        {
            if(p->val == p->next->val)
            {
                ListNode* to_del = p->next;
                p->next = p->next->next;
                delete to_del;
            }
            else p = p->next;
        }
        return head;
    }
};

int main()
{
    int data[] = {1,0,0,0,2,3,4,4,4};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode* L1 = create_list(nums);
    print_list(L1);
    Solution test;
    test.deleteDuplicates(L1);
    print_list(L1);
}
