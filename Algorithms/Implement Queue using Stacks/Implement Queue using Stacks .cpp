/*
	Implement Queue using Stacks
	Author:Xiaojun Huang
	Date:2015-08-03
*/
#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack1.push(x);
        queue_cap++;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!stack2.empty())
            stack2.pop();
        else
        {
            while(!stack1.empty())
            {
                int tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
            stack2.pop();
        }
        queue_cap--;
    }

    // Get the front element.
    int peek(void) {
        if(!stack2.empty())
            return stack2.top();
        else
        {
            while(!stack1.empty())
            {
                int tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
            return stack2.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return queue_cap == 0;
    }
    Queue()
    {
        queue_cap = 0;
    }
private:
    int queue_cap;
    stack<int> stack1;
    stack<int> stack2;
};


int main()
{
    Queue my_queue;
    my_queue.push(1);
    my_queue.push(2);
    cout<<my_queue.empty()<<endl;
    my_queue.push(3);
    my_queue.pop();
    cout<<my_queue.peek()<<endl;
    my_queue.pop();
    my_queue.pop();
    cout<<my_queue.empty()<<endl;
}
