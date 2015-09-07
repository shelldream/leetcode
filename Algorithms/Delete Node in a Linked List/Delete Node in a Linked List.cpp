/*
	Delete Node in a Linked List
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
        cout<<head->val<<"  ";
        head = head->next;
    }
    cout<<endl;
}

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node->next)
        {
            node->val = node->next->val;
            ListNode* tmp = node->next;
            node->next = node->next->next;
            delete tmp;
        }
    }
};


int main()
{
    int data[] = {1,2,3,4,5};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode* L1 = create_list(nums);
    ListNode* tmp = L1;
    while(tmp->val != 3)
        tmp = tmp->next;
    Solution solution;
    solution.deleteNode(tmp);
    print_list(L1);
}
