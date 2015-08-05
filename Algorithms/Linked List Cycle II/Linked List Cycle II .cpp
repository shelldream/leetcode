/*
	Linked List Cycle II
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

ListNode* create_cycle_list(vector<int> nums, int n)
{
    ListNode* head=NULL;
    ListNode* tail=NULL;
    ListNode* tmp = NULL;
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
        if(i == n)
            tmp = p;
    }
    tail->next = tmp;
    return head;
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
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode* pre = head->next;
        ListNode* post = head;
        while(pre)
        {
            if(pre == post)
                break;
            pre = pre->next;
            post = post->next;
            if(pre)
                pre = pre->next;
            else return NULL;
        }
        if(!pre)
            return NULL;
        post = head;
        pre = pre->next;
        while(pre != post)
        {
            pre = pre->next;
            post = post->next;
        }
        return pre;
    }
};


int main()
{
    int data[] = {0,1,2,3,4,5};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode* L1 = create_list(nums);
    ListNode* L2 = create_cycle_list(nums,3);
    Solution solution;
    cout<<(solution.detectCycle(L1)==NULL)<<endl;
    cout<<solution.detectCycle(L2)->val<<endl;
}
