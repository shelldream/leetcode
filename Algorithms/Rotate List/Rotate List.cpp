/*
	Rotate List
	Author:Xiaojun Huang
	Date:2015-08-06
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
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        int list_len = 1;
        ListNode* p = head;
        while(p)
        {
            p = p->next;
            if(p)
                list_len++;
        }
        ListNode* new_head = NULL;
        k %= list_len;
        int n = list_len - k;
        p = head;
        int i = 1;
        while(i < n)
        {
            p = p->next;
            i++;
        }
        new_head = p->next;
        if(!new_head)
            return head;
        p->next = NULL;
        ListNode* left_tail = new_head;
        while(left_tail->next)
            left_tail = left_tail->next;
        left_tail->next = head;
        return new_head;
    }
};

int main()
{
    int data[] = {1,2,3,4,5};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode* L1 = create_list(nums);
    print_list(L1);
    Solution solution;
    print_list(solution.rotateRight(L1,3));
}
