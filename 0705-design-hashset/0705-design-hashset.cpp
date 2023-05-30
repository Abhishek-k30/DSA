class MyHashSet {
public:
    int v[1000005]={-1};
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(v[key]<0){
            v[key]=0;
        } 
        v[key]=1;
    }
    
    void remove(int key) {
        v[key]=-1;
    }
    
    bool contains(int key) {
         if(v[key]>0)return true;
         return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */