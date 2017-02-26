/*
 *  基本的数据结构定义
 */

#ifndef BASIC_H_
#define BASIC_H_

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SingleLinkedList
{
public:
    SingleLinkedList()
    {
        _head = NULL;
    }
    
    SingleLinkedList(ListNode *copy_head)
    {
        if (NULL == copy_head)
        {   
            _head = NULL;
            return;
        }
         
        ListNode *tmp = copy_head;
        ListNode *tail = NULL;

        while (tmp != NULL)
        {
            ListNode *new_node = new ListNode(tmp->val);
            if (NULL == tail)
                _head = new_node;
            else
                tail->next = new_node;
            
            tail = new_node;
            tmp = tmp->next;
        }
    }
    
    SingleLinkedList(std::vector<int> &data)
    {
        _head = NULL;
        ListNode *tail = NULL;
        for (size_t i = 0; i < data.size(); ++i)
        {
            ListNode *tmp = new ListNode(data[i]);
            if (0 == i)
                _head = tmp;
            if (tail != NULL)
            {
                tail->next = tmp;
            }
            tail = tmp;
        }
    }
   
    SingleLinkedList(int *data, int n)
    {
        _head = NULL;
        ListNode *tail = NULL;
        for (size_t i = 0; i < n; ++i)
        {
            ListNode *tmp = new ListNode(*(data+i));
            if (0 == i)
                _head = tmp;
            if (tail != NULL)
            {
                tail->next = tmp;
            }
            tail = tmp;
        }
    }
    
    ~SingleLinkedList()
    {
        DestroySelf(); 
    }

    ListNode *getHead()
    {
        return _head;
    }
    
    void printList()
    {
        ListNode *tmp = _head;
        while (tmp)
        {
            std::cout<<tmp->val<<" ";
            tmp = tmp->next;
        }
        std::cout<<std::endl;
    }

private:
    ListNode *_head;
    
    void DestroySelf()
    {
        ListNode *head = _head;
        while (head)
        {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
            tmp = NULL;
        }
        _head = NULL;
    }
};

#endif
