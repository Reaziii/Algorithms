#include<bits/stdc++.h>

using namespace std;
struct trie
{
    struct trie *child[26];
    bool isend;

    trie(){
        memset(child,0,sizeof(child));
        isend = false;
    }
};

struct trie *root;
void insert(string s){
    struct trie *curr = root;
    for(char ch : s) {
        int idx = ch - 'a';
        if(curr->child[idx]==NULL){
            curr->child[idx] = new trie;
        }

        curr = curr->child[idx];
    }
    curr->isend = true;
}
bool search(string s){
    struct trie *curr = root;
    for(char ch : s){
        int idx = ch - 'a';
        if(curr->child[idx]==NULL){
            return false;
        }
        curr = curr->child[idx];
    }

    return curr->isend;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    root = new trie;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        insert(s);
    }

    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(search(s)) cout<<"present";
        else cout<<"Not present";
        cout<<endl;
    }
}
