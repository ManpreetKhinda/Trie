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
class TrieNode{
    public:
    TrieNode*next[2];
    TrieNode(){
        next[0]=NULL;
        next[1]=NULL;
    }
};
/*
void insertion(int num){
    temp=root;
    for(int i=31;i>=0;i--){
        int bit=(num>>1)&1;
        cout<<bit<<" ";
        if(temp->children[bit]==nullptr){
            temp->children[bit]=new TrieNode();
        }
        temp=temp->children[bit];
    }
}
*/

/*calculating xor
int calculatexor(TrieNode*cur, int num){
    int res=0;
    for(int i=31;i>=0;i--){
        int bit=((num>>i)&1)?0:1;
        if(cur->next[bit]){
            res<<=1;
            res|=1;
            cur=cur->next[bit];
        }
        else{
            res<<=1;
            res|=0;
            cur=cur->next[bit?0:1];
        }
    }
    return res;
}
*/

TrieNode * buildtrie(vi &a){
    TrieNode*root = new TrieNode();
    int n=a.size();
    for(int i=0;i<n;i++){
        int num=a[i];
        TrieNode*curr=new TrieNode();
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(curr->next[bit]==NULL){
                curr->next[bit]=new TrieNode();
            }
            curr=curr->next[bit];
        }
    }
    return root;
}
int solve(TrieNode*root, vi &a){
    int res=0;
    for(int i=0;i<a.size();i++){
        int num=a[i];
        TrieNode*it =root;
        int cur_max=0;
        for(int i=31;i>=0;i--){
            int bit=((num>>i)&1)?0:1;
            if(it->next[bit]){
                cur_max<<=1;
                cur_max|=1;
                it=it->next[bit];
            }
            else{
                cur_max<<=1;
                cur_max|=0;
                it=it->next[bit^1];
            }
        }
        res=max(res,cur_max);
    }   
    return res;
}
int main(){
    vi a={3,10,5,15,2};
    TrieNode*root = buildtrie(a);
    int ans=solve(root,a);
    cout<<ans;
}
