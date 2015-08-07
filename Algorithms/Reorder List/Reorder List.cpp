/*
	Reorder List
	Author:Xiaojun Huang
	Date:2015-08-07
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
    void reorderList(ListNode* head) {
        if(!head)
            return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast)
        {
            fast = fast->next;
            if(!fast)
                break;
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* right_head = slow->next;
        slow->next = NULL;
        right_head = reverse_list(right_head);
        head = merge_two_list(head,right_head);
    }
    ListNode* merge_two_list(ListNode* L1, ListNode* L2)
    {
        ListNode* ans = L1;
        while(L2)
        {
            ListNode* tmp1 = L1->next;
            ListNode* tmp2 = L2->next;
            L1->next = L2;
            L2->next = tmp1;
            L1 = tmp1;
            L2 = tmp2;
        }
        return L1;
    }
    ListNode* reverse_list(ListNode* head)
    {
        ListNode* ans = NULL;
        while(head)
        {
            if(head->next)
            {
                ListNode* tmp = head->next;
                head->next = ans;
                ans = head;
                head = tmp;
            }
            else
            {
                head->next = ans;
                ans = head;
                break;
            }
        }
        return ans;
    }
};


int main()
{
    //int data[] = {1,2,3,4,5,6,7,8,9,10};
    int data[] = {1};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode* L1 = create_list(nums);
    print_list(L1);
    Solution solution;
    solution.reorderList(L1);
    print_list(L1);
}
