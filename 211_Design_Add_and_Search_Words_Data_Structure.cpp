class TrieNode {
    public :
    TrieNode * child[26];
    bool isWord  ;
     TrieNode (){
        isWord = false ;
         for( auto & ch : child)
            ch = nullptr;
     }
};

class WordDictionary {
    bool DFS( TrieNode *  root , string & word , int pos ){
         if( !root) return false ;
        if( pos == word.size()) return root-> isWord ;
       

        char ch = word[ pos ];
        if( ch== '.'){
            for( int i  = 0 ; i < 26 ; i ++ ){
                if(  DFS( root -> child[i], word , pos +1 ) )
                    return true;
            }
            return false ;
        }

        else {
            
            return DFS( root -> child[ch-'a'] , word, pos + 1);
        }

    }
public:
TrieNode * root ;
    WordDictionary() {
        root= new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode * node = root;
         for( const auto & ch: word ){
            int pos = ch -'a';
            if (! node -> child[pos]) node -> child[pos ] = new TrieNode();
            node = node -> child[ pos ];
         }
         node -> isWord =  true ;
    }
    
    bool search(string word) {
        return DFS( root , word , 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
