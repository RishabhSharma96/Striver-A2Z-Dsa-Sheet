class Node{
public:

    Node* links[26] ;
    bool isEnd = false ;

    bool containWord(char ch){
        return (links[ch - 'a'] != nullptr) ? true : false;
    }

    void putWord(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* getNext(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        isEnd = true;
    }

    bool getEnd(){
        return isEnd;
    }
};

class Trie {
public:

    Node* root;    

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root ;
        for(auto it : word){
            if(!node->containWord(it)){
                node->putWord(it, new Node());
            }
            node = node->getNext(it) ;
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root ;
        for(auto it : word){
            if(!node->containWord(it)){
                return false;
            }
            node = node->getNext(it) ;
        }
        return (node->getEnd()) ? true : false;
    }
    
    bool startsWith(string word) {
        Node* node = root ;
        for(auto it : word){
            if(!node->containWord(it)){
                return false;
            }
            node = node->getNext(it) ;
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