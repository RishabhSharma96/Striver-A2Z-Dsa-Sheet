#include <bits/stdc++.h> 

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
    
    bool checkIfAllPrefixArePresent(string word) {
        Node* node = root ;
        for(auto it : word){
            if(node->containWord(it)){
                node = node->getNext(it) ;
                if(node->getEnd() == false){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true ;
    }
};

string completeString(int n, vector<string> &a){
    
    Trie t ;

    for(auto it : a){
        t.insert(it);
    }

    string ans = "";
    for(auto it : a){
        if(t.checkIfAllPrefixArePresent(it)){
            if(it.size() > ans.size()){
                ans = it ;
            }
            else if(it.size() == ans.size() && it < ans){
                ans = it;
            }
        }
    }

    return ans.size()>0 ? ans : "None";

}