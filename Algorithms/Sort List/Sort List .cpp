/*
	Sort List
	Author:Xiaojun Huang
	Date:2015-08-04

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
    ListNode* sortList(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while(p)
        {
            len++;
            p = p->next;
        }
        return list_sort(head,len);
    }
    ListNode* merge_lists(ListNode* L1, ListNode* L2)
    {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        while(L1 && L2)
        {
            if(L1->val < L2->val)
            {
                tail->next = L1;
                tail = L1;
                L1 = L1->next;
                tail->next = NULL;
            }
            else
            {
                tail->next = L2;
                tail = L2;
                L2 = L2->next;
                tail->next = NULL;
            }
        }
        while(L1)
        {
            tail->next = L1;
            tail = L1;
            L1 = L1->next;
            tail->next = NULL;
        }
        while(L2)
        {
            tail->next = L2;
            tail = L2;
            L2 = L2->next;
            tail->next = NULL;
        }
        ListNode* to_del = head;
        head = head->next;
        delete to_del;
        return head;
    }
    ListNode* list_sort(ListNode* head, int n)
    {
        if(!head)
            return NULL;
        if(n == 1)
            return head;
        else if(n == 2)
        {
            ListNode* tmp = head->next;
            if(tmp->val < head->val)
            {
                tmp->next = head;
                head->next = NULL;
                head = tmp;
            }
            return head;
        }
        else
        {
            int node_count = 1;
            ListNode* tmp = head;
            while(node_count < n/2)
            {
                node_count++;
                tmp = tmp->next;
            }
            ListNode* head2 = tmp->next;
            tmp->next = NULL;
            ListNode* L1 = list_sort(head,node_count);
            ListNode* L2 = list_sort(head2,n-node_count);
            return merge_lists(L1,L2);
        }
    }
};

int main()
{
    //int data[] = {10,2,4,6,1,8,2,10};
    int data[] = {10,2,4,6,1,7,3,98,32,522};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    ListNode* L = create_list(nums);
    print_list(L);
    Solution solution;
    print_list(solution.sortList(L));
}

/*
备注：
采用归并排序
1.


*/
