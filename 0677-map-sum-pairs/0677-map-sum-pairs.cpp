#include <unordered_map>
#include <string>

struct Node {
    Node* links[26];
    int cntPrefix = 0;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
   
    int getPrefix() {
        return cntPrefix;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string &word, int val) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->cntPrefix += val;
        }
    }

    int countWordsStartingWith(string &prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (node->containsKey(prefix[i])) {
                node = node->get(prefix[i]);
            } else {
                return 0;  // If the prefix doesn't exist, return 0
            }
        }
        return node->getPrefix();
    }
};

class MapSum {
    Trie trie;
    unordered_map<string, int> keyValMap;  // Store key-value pairs
    
public:
    MapSum() {
    }
    
    void insert(string key, int val) {
        int prevVal = keyValMap.count(key) ? keyValMap[key] : 0;  // Get previous value if exists
        int delta = val - prevVal;  // Calculate the difference
        trie.insert(key, delta);    // Adjust the trie with the difference
        keyValMap[key] = val;       // Update the map with the new value
    }
    
    int sum(string prefix) {
        return trie.countWordsStartingWith(prefix);  // Get sum of values for the prefix
    }
};
