/**
	Partition List
	Author:Xiaojun Huang
	Date:2015-08-22
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* ans_head = new ListNode(0);
        ListNode* ans_tail = ans_head;
        ListNode* p = new ListNode(0);
        ListNode* old_head = p;
        p->next = head;
        while(p->next)
        {
            if(p->next->val < x)
            {
                ans_tail->next = p->next;
                p->next = p->next->next;
                ans_tail = ans_tail->next;
                ans_tail->next = NULL;
            }
            else if(p->next)
                p = p->next;
        }
        ListNode* to_del1 = old_head;
        old_head = old_head->next;
        delete to_del1;
        ListNode* to_del2 = ans_head;
        ans_head = ans_head->next;
        delete to_del2;
        if(ans_head)
        {
            ans_tail->next = old_head;
            return ans_head;
        }
        else return old_head;
    }
};


int main()
{
    //int data[] = {1,2,3,4,5,6,7,8,9,10};
    //int data[] = {1,4,3,2,5,2};
    int data[] = {1,2,3};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode* head = create_list(nums);
    Solution solution;
    print_list(solution.partition(head,4));
}

/**
比x小的子链有可能为空（原链中所有元素都大于x），需要判断。

*/
