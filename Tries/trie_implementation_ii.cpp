#include <bits/stdc++.h> 

class Node{
public:

    Node* links[26] ;
    int prefixCount = 0;
    int endCount = 0;

    bool containWord(char ch){
        return (links[ch - 'a'] != nullptr) ? true : false;
    }

    void putWord(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* getNext(char ch){
        return links[ch - 'a'];
    }
};

class Trie{

    public:
    Node* root;    

    Trie() {
        root = new Node();
    }

    void insert(string &word){
        Node* node = root ;
        for(auto it : word){
            if(!node->containWord(it)){
                node->putWord(it, new Node());
            }
            node = node->getNext(it) ;
            node->prefixCount++ ;
        }
        node->endCount++ ;
    }

    int countWordsEqualTo(string &word){
        Node* node = root ;
        for(auto it : word){
            if(!node->containWord(it)){
                return 0 ;
            }
            node = node->getNext(it) ;
        }
        return node->endCount;
    }

    int countWordsStartingWith(string &word){
        Node* node = root ;
        for(auto it : word){
            if(!node->containWord(it)){
                return 0 ;
            }
            node = node->getNext(it) ;
        }
        return node->prefixCount ;
    }

    void erase(string &word){
        Node* node = root ;
        for(auto it : word){
            if(!node->containWord(it)){
                node->putWord(it, new Node());
            }
            node = node->getNext(it) ;
            node->prefixCount-- ;
        }
        node->endCount-- ;
    }
};
