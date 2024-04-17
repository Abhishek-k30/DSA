struct Node{
    Node* links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch, Node* n){
        links[ch-'a']=n;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
               
            }
             node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
       return searchUtil(root, word);
    }
    
    bool searchUtil(Node* root, string word){
         Node* node= root;
         
        for(int i=0; i<word.size(); i++){
            
            if(word[i]=='.'){
                for(char ch='a'; ch<='z'; ch++){
                    if(node->containsKey(ch)){
                        if(searchUtil(node->get(ch), word.substr(i+1)))
                            return true;
                    }
                }
                return false;
            }
            
            if( !node->containsKey(word[i]))
                return false;
            node=node->get(word[i]);
        }
        
        return node->isEnd();
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */