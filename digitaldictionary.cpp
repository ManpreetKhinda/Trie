#include <iostream>
#include <cmath>
#include <stack>
#include <cstring>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii vector<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

class node{
public:
    node* next[26];
    bool end;
    node(){
        rep(i,0,26){
            next[i]=NULL;
        }
        end=false;
    }
};
class Trie{
    private:
    node*root;
    public:
    Trie(){
        root=new node();
    }
    void insert(string &s){
        node*it=root;
        for(auto c:s){
            if(!it->next[c-'a']){
                it->next[c-'a']=new node();
            }
            it=it->next[c-'a'];
        }
        it->end=true;
    }
    void find(string&s){
        node*it=root;
        for(auto c:s){
            if(!it->next[c-'a']){
                cout<<"non existant"<<endl;
                insert(s);
                return;
            }
            it=it->next[c-'a'];

        }
        vector<string> res;
        printall(it,s,res,"");
        for(auto c:res){
            cout<<s<<c<<endl;
        }
    }
    void printall(node*it, string &s, vector<string> &res, string curr){
        if(it==NULL){
            return;
        }
        if(it->end){
            res.push_back(curr);
        }
        rep(i,0,26){
            if(it->next[i]){
                printall(it->next[i],s,res,curr+char('a'+i));
            }
        }
    }
};
int main(){
    Trie t;
    int n=4;
    vector<string> a(n);
    for(auto&i:a){
        cin>>i;
        t.insert(i);
    }
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        t.find(s);
    }


}