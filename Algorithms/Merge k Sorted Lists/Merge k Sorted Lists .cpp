/*
	Merge k Sorted Lists
	Author:Xiaojun Huang
	Date:2015-07-30
*/
#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void sink(vector<ListNode*>& my_heap, int i, int k)//下沉操作
{
    while(2*i <= k)
    {
        int min_index = 2*i;
        if(2*i+1 <= k && my_heap[2*i+1]->val < my_heap[2*i]->val)
            min_index = 2*i+1;
        if(my_heap[min_index]->val < my_heap[i]->val)
        {
            ListNode* tmp = my_heap[min_index];
            my_heap[min_index] = my_heap[i];
            my_heap[i] = tmp;
            i = min_index;
        }
        else
            break;
    }
}

void swim(vector<ListNode*>& my_heap, int i)
{
    while(i/2)
    {
        if(my_heap[i]->val < my_heap[i/2]->val)
        {
            ListNode* tmp = my_heap[i];
            my_heap[i] = my_heap[i/2];
            my_heap[i/2] = tmp;
            i /= 2;
        }
        else
            break;
    }
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        vector<ListNode*> my_heap; //小顶堆
        my_heap.push_back(NULL); //my_heap[0]不用
        int k = lists.size();
        int heap_cap = 0;
        for(int i = 0;i < k;i++)
        {
            if(lists[i])
            {
                my_heap.push_back(lists[i]);
                swim(my_heap,heap_cap+1);
                heap_cap++;
            }
        }
        while(heap_cap)
        {
            ListNode* min_ListNode = my_heap[1];
            ListNode* next_ListNode = min_ListNode->next;
            if(tail)
            {
                tail->next = min_ListNode;
                tail = tail->next;
                tail->next = NULL;
            }
            else
            {
                head = min_ListNode;
                tail = head;
                tail->next = NULL;
            }
            if(next_ListNode)
            {
                my_heap[1] = next_ListNode;
                sink(my_heap, 1,heap_cap);
            }
            else//有一条链已经用尽
            {
                my_heap[1] = my_heap[heap_cap];
                my_heap[heap_cap] = NULL;
                heap_cap--;
                sink(my_heap,1,heap_cap);
            }
        }
        return head;
    }
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


int main()
{
    int data1[] = {-8,2,4};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    vector<int> vec1(data1,data1+n1);
    ListNode* L1 = create_list(vec1);
    print_list(L1);
    int data2[] = {-9,-9,-9,-9,-8,-5,-3,-2,1};
    int n2 = sizeof(data2)/sizeof(data2[0]);
    vector<int> vec2(data2,data2+n2);
    ListNode* L2 = create_list(vec2);
    print_list(L2);
    int data3[] = {-9,-7,-5,-3,-3,-1,0,3,4};
    int n3 = sizeof(data3)/sizeof(data3[0]);
    vector<int> vec3(data3,data3+n3);
    ListNode* L3 = create_list(vec3);
    print_list(L3);
    int data4[] = {-9,-7,-6,-4,-2,-1,3,4};
    int n4 = sizeof(data4)/sizeof(data4[0]);
    vector<int> vec4(data4,data4+n4);
    ListNode* L4 = create_list(vec4);
    print_list(L4);
    int data5[] = {-10,-3,0};
    int n5 = sizeof(data5)/sizeof(data5[0]);
    vector<int> vec5(data5,data5+n5);
    ListNode* L5 = create_list(vec5);
    print_list(L5);
    int data6[] = {-9,0,4};
    int n6 = sizeof(data6)/sizeof(data6[0]);
    vector<int> vec6(data6,data6+n6);
    ListNode* L6 = create_list(vec6);
    print_list(L6);
    int data7[] = {-8,-8};
    int n7 = sizeof(data7)/sizeof(data7[0]);
    vector<int> vec7(data7,data7+n7);
    ListNode* L7 = create_list(vec7);
    print_list(L7);
    vector<ListNode*> lists;
    lists.push_back(L1);
    lists.push_back(L2);
    lists.push_back(L3);
    lists.push_back(L4);
    lists.push_back(L5);
    lists.push_back(L6);
    lists.push_back(L7);
    Solution solution;
    vector<ListNode*> lists1;
    lists1.push_back(NULL);
    lists1.push_back(NULL);
    lists1.push_back(L1);
    ListNode* L =solution.mergeKLists(lists);
    print_list(L);
}




/*
备注：
利用小顶堆


*/
