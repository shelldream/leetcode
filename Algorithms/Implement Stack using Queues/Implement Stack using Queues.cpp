/**
	Implement Stack using Queues
	Author:Xiaojun Huang
	Date:2015-09-08

*/

#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if(queue2.empty())
            queue1.push(x);
        else queue2.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(!queue2.empty())
        {
            while(queue2.size() > 1)
            {
                int tmp = queue2.front();
                queue1.push(tmp);
                queue2.pop();
            }
            queue2.pop();
        }
        else
        {
            while(queue1.size() > 1)
            {
                int tmp = queue1.front();
                queue2.push(tmp);
                queue1.pop();
            }
            queue1.pop();
        }
    }

    // Get the top element.
    int top() {
        if(!queue2.empty())
        {
            while(queue2.size() > 1)
            {
                int tmp = queue2.front();
                queue1.push(tmp);
                queue2.pop();
            }
            int ans = queue2.front();
            queue2.pop();
            queue1.push(ans);
            return ans;
        }
        else
        {
            while(queue1.size() > 1)
            {
                int tmp = queue1.front();
                queue2.push(tmp);
                queue1.pop();
            }
            int ans = queue1.front();
            queue1.pop();
            queue2.push(ans);
            return ans;
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return queue1.empty()&&queue2.empty();
    }
private:
    int stack_cap;
    queue<int> queue1;
    queue<int> queue2;
};



int main()
{
    Stack my_stack;
    my_stack.push(0);
    my_stack.push(1);
    my_stack.push(2);
    cout<<my_stack.top()<<endl;
    my_stack.pop();
    my_stack.push(3);
    cout<<my_stack.top()<<endl;
}
