class MinStack {
public:
    
    multiset<int> st;
    vector<int> v;
    
   
    MinStack() {
        
    }
    
    void push(int val) {
        st.insert(val);
        v.push_back(val);
    }
    
    void pop() {
        st.erase(st.find(v.back()));
        v.pop_back();
        
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return *st.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */