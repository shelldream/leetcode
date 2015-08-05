/*
	Insertion Sort List
	Author:Xiaojun Huang
	Date:2015-08-05
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ans_head = NULL;
        ListNode* ans_tail = NULL;
        while(head)
        {
            ListNode* new_head = head->next;
            if(ans_head == NULL)
            {
                ans_head = head;
                ans_tail = head;
                ans_tail->next = NULL;
            }
            else
            {
                if(head->val <= ans_head->val)
                {
                    head->next = ans_head;
                    ans_head = head;
                }
                else
                {
                    ListNode* p = ans_head;
                    while(p->next && p->next->val < head->val)
                        p = p->next;
                    head->next = p->next;
                    p->next = head;
                }
            }
            head = new_head;
        }
        return ans_head;
    }
};


int main()
{
    int data[] = {6,10,1,9,4,2,8,5,3,7};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode* L1 = create_list(nums);
    print_list(L1);
    Solution solution;
    print_list(solution.insertionSortList(L1));
}
