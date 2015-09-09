/**
	Intersection of Two Linked Lists
	Author:Xiaojun Huang
	Date:2015-09-09

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

ListNode* getNode(ListNode* head, int val)
{
    while(head && head->val != val)
    {
        head = head->next;
    }
    return head;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getListLen(headA);
        int lenB = getListLen(headB);
        int delta = lenA > lenB ? (lenA-lenB) : (lenB-lenA);
        if(lenA > lenB)
            headA = moveNsteps(headA, delta);
        else headB = moveNsteps(headB, delta);
        while(headA && headB && headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }

    ListNode* moveNsteps(ListNode* head, int n)
    {
        while(n)
        {
            head = head->next;
            n--;
        }
        return head;
    }

    int getListLen(ListNode* head)
    {
        int ans = 0;
        ListNode* p = head;
        while(p)
        {
            ans++;
            p = p->next;
        }
        return ans;
    }
};

int main()
{
    int data1[] = {1,2,3,4,5,6,7,8,9,10};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    vector<int> nums1(data1,data1+n1);
    ListNode* L1 = create_list(nums1);
    ListNode* tmp = getNode(L1,5);
    int data2[] = {11,12,13,14};
    int n2 = sizeof(data2)/sizeof(data2[0]);
    vector<int> nums2(data2,data2+n2);
    ListNode* L2 = create_list(nums2);
    ListNode* p = L2;
    while(p->next)
    {
        p = p->next;
    }
    p->next = tmp;
    Solution test;
    cout<<test.getIntersectionNode(L1,L2)->val<<endl;
}
