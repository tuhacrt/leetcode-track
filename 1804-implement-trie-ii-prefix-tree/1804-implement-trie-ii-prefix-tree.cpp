class TrieNode {
    public:
        TrieNode* links[26];
        int wordEnd = 0;
        int wordStart = 0;
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        
        for (char& w: word) {
            int charIndex = w - 'a';
            if (!node->links[charIndex]) node->links[charIndex] = new TrieNode();
            node = node->links[charIndex];
            node->wordStart++;
        }
        node->wordEnd++;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for (char& w: word) {
            int idx = w -'a';
            if (!node->links[idx]) return 0;
            node = node->links[idx];
        }
        return node->wordEnd;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* node = root;
        for(char& w: prefix) {
            int idx = w -'a';
            if (!node->links[idx]) return 0;
            node = node->links[idx];
        }
        return node->wordStart;
    }
    
    void erase(string word) {
        TrieNode* node=root;
        for (char& w:word){
            int idx= w-'a';
            node=node->links[idx];
            node->wordStart--;
        }
        node->wordEnd--;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */