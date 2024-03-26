class SmallestInfiniteSet {
public:
    set<int> st;
    SmallestInfiniteSet() {
        for(int i=1; i<=1001; i++)st.insert(i);
    }
    
    int popSmallest() {
        auto it= st.begin();
        int ans=*it;
        st.erase(it);
        return ans;
        
    }
    
    void addBack(int num) {
        if(st.find(num)==st.end())st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */