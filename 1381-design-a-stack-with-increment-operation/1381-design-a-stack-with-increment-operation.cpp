class CustomStack {
public:
    vector<int> v;
    int idx ;
    int size;
    CustomStack(int maxSize) {
        v.resize(maxSize);
        idx = 0;
        size = maxSize;
    }
    
    void push(int x) {
        if(idx<size){
            v[idx++] = x;
         }
    }
    
    int pop() {
        int cur = -1;
        
        if(idx>0){
            cur = v[--idx];
        }
        return cur;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i<min(k, size); i++){
            v[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */