class TrieNode {
public:
    TrieNode* child[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
        isWord = false;
    }
};
class Trie {
    TrieNode * root  ;
public:
    Trie() {
        root  = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * node = root ;
        for( char & ch :  word) {
            int pos = ch -'a';
            if( ! node -> child[pos]) node -> child[ pos ] = new TrieNode();
            node = node -> child[pos ];
        }
        node -> isWord = true ;
    }
    
    bool search(string word) {
        TrieNode * node=  root ;
        for( const auto &  ch   : word) {
            int  i = ch -'a';
            if( !node -> child[i]) return false ;
            node = node -> child[i];
        }
        return node -> isWord;
    }
    
    bool startsWith(string prefix) {
         TrieNode * node = root;
         for( const auto & ch : prefix ){
            int  i = ch -'a';
            if( ! node -> child[i]) return false ;;
            node = node -> child[i];
         }
         return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
