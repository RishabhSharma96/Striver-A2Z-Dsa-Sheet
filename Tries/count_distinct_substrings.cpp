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

int countDistinctSubstrings(string &s)
{
    int n = s.size(), cnt=1;

    Node* root = new Node() ;

    for(int i=0 ; i<n ; i++){
        Node* node = root;
        for(int j=i ; j<n ; j++){
            if(!node->containWord(s[j])){
                cnt++;
                node->putWord(s[j],new Node());
            }
            node = node->getNext(s[j]);
        }
    }
    return cnt ;
}