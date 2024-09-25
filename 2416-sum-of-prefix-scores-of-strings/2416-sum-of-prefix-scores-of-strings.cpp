struct Node{
    Node* links[26];
    int cntPrefix=0;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    
    int getPrefix(){
        return cntPrefix;
    }
};
class Trie{
   
  Node* root;
    public:

    Trie(){
         root=new Node();
    }

    void insert(string &word){
        Node* node= root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
             
             node= node->get(word[i]);
             node->increasePrefix();
           
        }
        
    }

    

    int countWordsStartingWith(string &word){
        int cnt = 0;
        Node* node=root;
        for(auto &ch: word){
            node = node->get(ch);
            cnt+= node->getPrefix();
            
        }
        return cnt;
        
    }

    
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(auto &word : words){
              trie.insert(word);
        }
        
        vector<int> ans;
        
        for(auto &word: words){
                 
               int cnt =trie.countWordsStartingWith(word);
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};