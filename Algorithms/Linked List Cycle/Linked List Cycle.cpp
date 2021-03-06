/*
	Linked List Cycle
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

ListNode* create_cycle_list(vector<int> nums)
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
    tail->next = head;
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
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode* pre = head->next;
        ListNode* post = head;
        while(pre)
        {
            if(pre == post)
                return true;
            pre = pre->next;
            post = post->next;
            if(pre)
                pre = pre->next;
            else return false;
        }
        return false;
    }
};


int main()
{
    int data[] = {1,2,3,4,5};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode* L1 = create_list(nums);
    ListNode* L2 = create_cycle_list(nums);
    Solution solution;
    cout<<solution.hasCycle(L1)<<endl;
    cout<<solution.hasCycle(L2)<<endl;
}
