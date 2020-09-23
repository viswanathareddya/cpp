#include <bits/stdc++.h>

using namespace std;

struct Trie{
    bool isEnd;
    unordered_map<char, Trie*> list_c;
    map<char,int> count;
};

struct Trie* getnewTrienode(){

    Trie* node= new Trie;
    node->isEnd =  false;
    return node;
}

void insert(Trie* &root, string name){
    if(root==nullptr){
        root= getnewTrienode();
    }

    Trie *temp =root;
    for(int i=0;i<name.length();i++){
        char c=name[i];
        if(temp->list_c.find(c)==temp->list_c.end()){
            temp->list_c[c] = getnewTrienode();
            temp->count[c] = 1;
        }
        else{
            temp->count[c]++;
        }
        temp=temp->list_c[c];
    }
    temp->isEnd=true;
}

int search(Trie* &root, string name){
    int t_count=0;
    if(root==nullptr){
        return 0;
    }
    Trie *temp =root;
    for(int i=0;i<name.length();i++){
        char c=name[i];
        if(temp->list_c.find(c)==temp->list_c.end()){
            return 0;
            break;
        }
        t_count=temp->count[c];
        temp=temp->list_c[c];
    }
    return t_count;

    
}

int main()
{
   int N;
   cin >> N;
   cin.ignore(numeric_limits<streamsize>::max(),'\n');
   Trie* root=nullptr;
   while(N--){
       string query,name;
       cin >> query;
       if (query=="add"){
           cin >> name;
           insert(root,name);
       }
       if (query=="find"){
           cin >> name;
           int w_c=search(root,name);
           cout << w_c << endl;
       }
   }

    return 0;
}
