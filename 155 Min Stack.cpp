#include <climits>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        this -> curNum = INT_MAX;
    }
    
    void push(int x) {
        (this -> myStack).push_back(x);
        if(x <= this -> curNum)
        {
            (this -> myMinStack).push_back(x);
            this -> curNum = x;
        }
    }
    
    void pop() {
        int size = (this -> myStack).size();
        if(size > 0)
        {
            int x = (this -> myStack)[size - 1];
            (this -> myStack).pop_back();
            if(this -> getMin() == x)
            {
                (this -> myMinStack).pop_back();
                this -> curNum = this -> getMin();
            }
        }
        
    }
    
    int top() {
        int size = (this -> myStack).size();
        if(size > 0)
            return myStack[size - 1];
        else
            return -1;           
    }
    
    int getMin() {
        int size = (this -> myMinStack).size();
        if(size > 0)
            return myMinStack[size - 1]; 
        else
            return INT_MAX;
    }

    private:
        vector<int> myStack;
        vector<int> myMinStack;
        int curNum;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */