struct Node{
    Node* links[2];
    int frequency;
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
            node->frequency++;
        }
    }
    
    int getMax(int num){
        Node* node= root;
        int maxNum=0;
        for(int i=31; i>=0; i--){
            int bit= (num>>i)&1;
            if(node->containsKey(1-bit) && node->get(1-bit)->frequency>0){
                maxNum=maxNum | (1<<i);
                node=node->get(1-bit);
            }
            else node= node->get(bit);
        }
        
        return maxNum;
    }  
    
    void erase(int num){
        Node* node=root;
        for(int i=31; i>=0; i--){
            int bit= (num>>i) & 1;
            if(node->containsKey(bit)){
                node=node->get(bit);
                node->frequency--;
            }
            else break;
        }
    }
};
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n=nums.size();
        Trie trie;
        sort(nums.begin(), nums.end());
        int l=0, ans=0;
        for(int r=0; r<n; r++){
            trie.insert(nums[r]);
            while(l<r && nums[r]-nums[l]>nums[l]){
                trie.erase(nums[l]);
                l++;
            }
            
            ans=max(ans, trie.getMax(nums[r]));
        }
    
        return ans;
    }
};