class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty() && q2.empty())
            return -1;
        while(!q1.empty())
        {
            int curNum = q1.front();
            q1.pop();
            if(q1.empty())
            {
                std::swap(q1,q2);
                return curNum;
            }
            else
            {
                q2.push(curNum);
            }
        }
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty() && q2.empty())
            return -1;
        while(!q1.empty())
        {
            int curNum = q1.front();
            q1.pop();
            q2.push(curNum);
            if(q1.empty())
            {
                std::swap(q1,q2);
                return curNum;
            }
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
    std::queue<int> q1;
    std::queue<int> q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */