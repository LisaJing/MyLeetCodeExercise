class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s2.push(x);
        if(s1.empty())
        {
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s1.empty() && s2.empty())
            return -1;
        if(!s1.empty())
        {
            int num = s1.top();
            s1.pop();
            return num;
        }
        else
        {
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            int num = s1.top();
            s1.pop();
            return num;
        }
        
    }
    
    /** Get the front element. */
    int peek() {
        if(s1.empty() && s2.empty())
            return -1;
        if(!s1.empty())
        {
            return s1.top();
        }
        else
        {
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            return s1.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */