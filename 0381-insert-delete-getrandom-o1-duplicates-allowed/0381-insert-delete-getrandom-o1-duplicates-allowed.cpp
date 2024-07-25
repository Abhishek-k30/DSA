class RandomizedCollection {
public:
    unordered_map<int, vector<int>> mpp;
    vector<pair<int, int>> nums;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool flag = false;
         if(mpp.find(val) == mpp.end()){ 
             flag = true;
        }
        mpp[val].push_back(nums.size());
        nums.push_back(pair<int, int>(val, mpp[val].size() - 1));
       
        return flag;
    }
    
    bool remove(int val) {
        if(mpp.find(val) !=mpp.end()){
            auto last = nums.back();
            int idx = mpp[val].back();
            mpp[last.first][last.second] = idx;
            mpp[val].pop_back();
            if(mpp[val].empty())mpp.erase(val);
            swap(nums[idx], nums[nums.size()-1]);
            nums.pop_back();
            return true;
            
            // 3 0 2 3
            // 5 1 5
        }
        return false;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */