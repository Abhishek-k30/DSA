struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    
    Node* get(int bit){
        return links[bit];
    }
    
    void put(int bit, Node* node){
        links[bit]=node;
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root=new Node();
    }
    
    void insert(int num){
        Node* node= root;
        for(int i=31; i>=0; i--){
            int bit= (num>>i) &1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node= node->get(bit);
        }
    }
    
    int getMax(int num){
        Node* node= root;
        int maxNum=0;
        for(int i=31; i>=0; i--){
            int bit= (num>>i)&1;
            if(node->containsKey(1-bit)){
                maxNum=maxNum | (1<<i);
                node=node->get(1-bit);
            }
            else node= node->get(bit);
        }
        
        return maxNum;
    }   
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<pair<pair<int, int>, int>> pq; // {{mi,xi},idx }
        for(int i=0; i<queries.size(); i++){
            pq.push_back({{queries[i][1], queries[i][0]}, i});
        }
        sort(pq.begin(), pq.end());
        sort(nums.begin(), nums.end());
        vector<int> ans(n);
        
        Trie trie;
        int idx=0;
        int sz=nums.size();
        for(int i=0; i<n; i++){
            int mi= pq[i].first.first;
            int xi= pq[i].first.second;
            int qInd= pq[i].second;
            while(idx<sz && nums[idx]<=mi){
                trie.insert(nums[idx]);
                idx++;
            }
            
            if(idx==0)ans[qInd]=-1;
            else ans[qInd]= trie.getMax(xi);
        }
        
        return ans;
    }
};