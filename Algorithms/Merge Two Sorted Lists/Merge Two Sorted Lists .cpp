/*
	Merge Two Sorted Lists
	Author:Xiaojun Huang
	Date:2015-07-23

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
    ListNode* head;
    ListNode* tail;
    void insert_list(ListNode* p)
    {
        if(head == NULL)
        {
            head = p;
            tail = head;
        }

        else
        {
            tail->next = p;
            tail = tail->next;
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        head = NULL;
        tail = NULL;
        while(l1&&l2)
        {
            int x = l1->val;
            int y = l2->val;
            if(x<y)
            {
                ListNode* tmp = l1;
                l1 = l1->next;
                insert_list(tmp);
            }
            else
            {
                ListNode* tmp = l2;
                l2 = l2->next;
                insert_list(tmp);
            }
        }
        while(l1)
        {
            ListNode* tmp = l1;
            l1 = l1->next;
            insert_list(tmp);
        }
        while(l2)
        {
            ListNode* tmp = l2;
            l2 = l2->next;
            insert_list(tmp);
        }
        return head;
    }
};

int main()
{
    int data1[] = {0,1,2,3};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    vector<int> nums1(data1,data1+n1);
    ListNode* L1 = create_list(nums1);
    print_list(L1);
    int data2[] = {-3,-2,-1,0,1,2,3,4,5};
    int n2 = sizeof(data2)/sizeof(data2[0]);
    vector<int> nums2(data2,data2+n2);
    ListNode* L2 = create_list(nums2);
    print_list(L2);
    Solution solution;
    print_list(solution.mergeTwoLists(L1,L2));
}

/*
หตร๗


*/
