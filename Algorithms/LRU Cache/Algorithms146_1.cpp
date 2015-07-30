/*
	LRU Cache
	Author:Xiaojun Huang
	Date:2015-07-02
*/
#include <iostream>
#include <map>
using namespace std;

struct Node
{
    int key;
    Node* next;
    Node* pre;
    Node(int x){key = x;next = NULL;pre = NULL;};
};


class LRUCache{
private:
    map<int,int> dict;
    map<int,Node*> recently_used;
    Node* head;
    Node* tail;
    int max_capacity;
    int now_capacity;
public:
    LRUCache(int capacity) {
        head = NULL;
        tail = NULL;
        now_capacity = 0;
        max_capacity = capacity;
    }

    void queue_push(int key)//队末压入元素
    {
        Node* node = new Node(key);
        if(tail==NULL)//队列为空
        {
            tail = node;
            head = node;
        }
        else
        {
            node->pre = tail;
            tail->next = node;
            tail = node;
        }
        now_capacity++;
        recently_used[key] = node;
    }

    void queue_pop()//队首弹出元素
    {
        if(head == NULL)
            return;
        Node* to_del_node = head;
        int to_del_val = head->key;
        if(now_capacity == 1)//队列中只有一个元素
        {
            delete to_del_node;
            head = NULL;
            tail = NULL;
        }
        else
            {
                head = head->next;
                head->pre = NULL;
                delete to_del_node;
            }
        now_capacity--;
        recently_used.erase(to_del_val);
        dict.erase(to_del_val);
    }

    void queue_mv_tail(int key)//将队列中间元素移动到队列队尾
    {
        if(head == NULL || now_capacity == 1)
            return;
        Node* to_mv_node = recently_used[key];
        if (to_mv_node == tail)
            return;
        if(to_mv_node == head)//待移动元素在队首
        {
            head = head->next;
            head->pre = NULL;
            to_mv_node->next = NULL;
            tail->next = to_mv_node;
            to_mv_node->pre = tail;
            tail = tail->next;
        }
        else
            {
                to_mv_node->pre->next = to_mv_node->next;
                to_mv_node->next->pre = to_mv_node->pre;
                to_mv_node->pre = tail;
                tail->next = to_mv_node;
                to_mv_node->next = NULL;
                tail = tail->next;
            }
    }

    void refresh(int key)//将key添加到队列中
    {
        if(recently_used.count(key)==0)//不在队列中
            queue_push(key);
        else
            queue_mv_tail(key);
        if(now_capacity > max_capacity)
            queue_pop();
    }

    int get(int key) {
        if(dict.count(key))
        {
            refresh(key);
            return dict[key];
        }
        else return -1;
    }

    void set(int key, int value) {
        dict[key] = value;
        refresh(key);
    }
};


int main()
{
    LRUCache test(2);
    /*
    test.set(2,1);
    test.set(1,1);
    cout<<test.get(2)<<endl;
    test.set(4,1);
    cout<<test.get(1)<<endl;
    cout<<test.get(2)<<endl;*/

    cout<<test.get(2)<<endl;
    test.set(2,6);
    cout<<test.get(1)<<endl;
    test.set(1,5);
    test.set(1,2);
    cout<<test.get(1)<<endl;
    cout<<test.get(2)<<endl;

}
