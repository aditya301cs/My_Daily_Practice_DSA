class MyQueue {
private:
    stack<int> stack1; // Stack for enqueue operations
    stack<int> stack2; // Stack for dequeue operations

    // Helper function to transfer elements from stack1 to stack2
    void transfer() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    MyQueue() {
        // Constructor
    }
    
    // Push element x to the back of the queue
    void push(int x) {
        stack1.push(x);
    }
    
    // Removes the element from the front of the queue and returns it
    int pop() {
        if (stack2.empty()) {
            transfer();
        }
        int topElement = stack2.top();
        stack2.pop();
        return topElement;
    }
    
    // Returns the element at the front of the queue
    int peek() {
        if (stack2.empty()) {
            transfer();
        }
        return stack2.top();
    }
    
    // Returns true if the queue is empty, false otherwise
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
