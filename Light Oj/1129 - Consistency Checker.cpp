#include<bits/stdc++.h>
#define ALPHA_SIZE 10
using namespace std;
const char ch = '0';
 
struct TrieNode{
   struct TrieNode *children[ALPHA_SIZE];
   bool isEndOfWord;
}*root;
 
bool insert(string key,TrieNode *nCrawl){
    int l = key.length();
    for(int i = 0; i < l; i++){
        int index = key[i] - ch;
        if(!nCrawl -> children[index]){
            nCrawl -> children[index] = new TrieNode();
        }
        nCrawl = nCrawl -> children[index];
 
        if(nCrawl -> isEndOfWord) return false;
    }
    nCrawl -> isEndOfWord = true;
 
    return true;
}
 
void deleteNode(TrieNode *currentNode){
    for(int i = 0; i < ALPHA_SIZE; i++)
        if(currentNode->children[i])
            deleteNode(currentNode->children[i]);
 
    delete(currentNode);
}
 
int main(){
    int t, n, tc = 1;
    string str;
    cin >> t;
 
    while(t--){
        root = new TrieNode();
        cin >> n;
        bool cont = true;
        vector <string> vtr;
        for(int i = 0; i < n; i++){
            cin >> str;
            vtr.push_back(str);
        }
        sort(vtr.begin(),vtr.end());
        for(int i = 0; i < n; i++){
            cont = insert(vtr[i],root);
            if(cont == false) break;
        }
        printf("Case %d: ", tc++);
        if(cont) cout << "YES\n";
        else cout << "NO\n";
        deleteNode(root);
    }
    return 0;
}