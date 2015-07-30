/*
	Reverse Linked List II
	Author:Xiaojun Huang
	Date:2015-07-30

*/

#include <iostream>
#include <algorithm>
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int node_count = 1;
        ListNode* ans = head;
        ListNode* tail = NULL;
        while(head && node_count<m)
        {
            tail = head;
            head = head->next;
            node_count++;
        }
        ListNode* reverse_head = NULL;
        ListNode* reverse_tail = NULL;
        while(head && node_count<=n)
        {
            ListNode* next_node = head->next;
            if(reverse_head)
                head->next = reverse_head;
            else
            {
                head->next = NULL;
                reverse_tail = head;
            }
            reverse_head = head;
            head = next_node;
            node_count++;
        }
        if(tail)
            tail->next = reverse_head;
        else
            ans = reverse_head;
        reverse_tail->next = head;
        return ans;
    }
};

int main()
{
    int data[] = {1,2,3,4,5,6,7};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode* L1 = create_list(nums);
    print_list(L1);
    Solution solution;
    print_list(solution.reverseBetween(L1,3,5));
    //print_list(solution.reverseBetween(L1,2,2));
}

/*
หตร๗


*/
