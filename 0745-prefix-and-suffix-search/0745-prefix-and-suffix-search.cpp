struct Node{
    Node* links[26];
    set<int, greater<int>> st;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
     
    void put(char ch, Node* n){
        links[ch-'a']=n;
       
    }

    Node* get(char ch){
        return links[ch-'a'];
    }
};
class Trie {

public:

    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word, int ind) {
        Node* node=root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                Node* temp= new Node();
                node->put(word[i], temp);
            }
            node=node->get(word[i]);
            (node->st).insert(ind);
            
        }
       
    }

    set<int , greater<int>> search(string word){
        Node* node= root;
        set<int , greater<int>> em;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i]))
                return em;
            node= node->get(word[i]);
        }
        return node->st;
    }
   
   
    
};
class WordFilter {
public:
    Trie trie1, trie2;
    WordFilter(vector<string>& words) {
        map<string, int> m;
        for(int i=0; i<words.size(); i++)m[words[i]]=i;
        set<string> t;
        for(int i=0; i<words.size(); i++){
            if(t.find(words[i])==t.end()){
                trie1.insert(words[i], m[words[i]]);
            }
            else t.insert(words[i]);
        }
        
        map<string, int> m2;
        for(int i=0; i<words.size(); i++){
            reverse(words[i].begin(), words[i].end());
            m2[words[i]]=i;
        }
        
        set<string> t2;
        for(int i=0; i<words.size(); i++){
            if(t2.find(words[i])==t2.end())
                trie2.insert(words[i] , m2[words[i]]);
            else t.insert(words[i]);
        }
        
    }
    
    int f(string pref, string suff) {
         reverse(suff.begin(), suff.end());
        set<int, greater<int>> s1=trie1.search(pref);
        set<int, greater<int>> s2=trie2.search(suff);
        
        int mxInd=-1;
        for(auto it: s1){
            if(s2.find(it)!=s2.end()){
                mxInd=it;
                break;
            }
        }
        
        return mxInd;
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */