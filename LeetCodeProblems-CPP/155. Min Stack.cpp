class MinStack {
public:

    stack<int> s1,s2;

    MinStack() {
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.empty())
            s2.push(val);
        else
            s2.push(min(s2.top(),val));
    }
    
    void pop() {
        s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

// OR (better approach i feel)

class MinStack {
public:

    stack<pair<int, int> > s;
    MinStack() {
        
    }
    
    void push(int val) {
        int ele;
        if(s.empty()){
            ele = val;
        }else{
            ele = min(s.top().second, val);
        }
        s.push(make_pair(val,ele));
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};