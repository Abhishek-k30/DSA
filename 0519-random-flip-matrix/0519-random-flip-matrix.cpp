class Solution {
public:
    unordered_set<int> st;
    int row=0 , col=0;
    int mx = 0;
    Solution(int m, int n) {
        row = m;
        col = n;
        mx= n*m;
    }
    
    vector<int> flip() {
        if(st.size()==mx)return {};
        
        int cur = rand()%mx;
        
        while(st.find(cur)!=st.end()){
            cur = (++cur)%mx;
        }
        
        st.insert(cur);
        
        return {cur/col, cur%col};
    }
    
    void reset() {
        st.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */