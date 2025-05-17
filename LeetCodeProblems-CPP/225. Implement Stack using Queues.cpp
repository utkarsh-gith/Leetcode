class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q2.empty()){
            q1.push(x);
        }
        else{
            q2.push(x);
        }
    }
    
    int pop() {
        int n = 0;
        if(q2.empty()){
            int c = q1.size();
            while(n<c-1){
                q2.push(q1.front());
                q1.pop();
                n++;
            }
            n = q1.front();
            q1.pop();
            return n;
        }
        else{
            int c = q2.size();
            while(n<c-1){
                q1.push(q2.front());
                q2.pop();
                n++;
            }
            n = q2.front();
            q2.pop();
            return n;
        }
    }
    
    int top() {
        int n = 0;
        if(q2.empty()){
            int c = q1.size();
            while(n<c-1){
                q2.push(q1.front());
                q1.pop();
                n++;
            }
            n = q1.front();
            q2.push(n);
            q1.pop();
            return n;
        }
        else{
            int c = q2.size();
            while(n<c-1){
                q1.push(q2.front());
                q2.pop();
                n++;
            }
            n = q2.front();
            q1.push(n);
            q2.pop();
            return n;
        }
    }
    
    bool empty() {
        if(q1.empty() && q2.empty())
            return 1;
        else 
            return 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */