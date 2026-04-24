class MinStack {
private:
    std::stack<int> s{};
    std::stack<int> min{};
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(min.empty() || min.top() >= val){
            min.push(val);
        }
    }
    
    void pop() {
        
        if(s.top() == min.top()){
            min.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};
/*
    [1,2,0] ret 0 remove back ret 1

    s= [-2,-2] .pop() checks if the back is the same back as min if so pop, else dont
    mins = [-2,-2] get min first returns .back()
*/