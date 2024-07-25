class RandomizedSet {
public:
     unordered_map<int, int> m;
    vector<int> nums;
    
    RandomizedSet() {
       
    }
    
    bool insert(int val) {
       if(m.find(val) == m.end()){
           nums.push_back(val);
           m[val] = nums.size()-1;
           return true;
       }
        return false;
    }
    
    bool remove(int val) {
        if(m.find(val) != m.end()){
            int last = nums.back();
            int idx = m[val];
            swap(nums[idx], nums[nums.size()-1]);
            nums.pop_back();
            m[last] = idx;
            m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */