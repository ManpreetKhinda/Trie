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
    node*next[2];
    node(){
        rep(i,0,2){
            next[i]=NULL;
        }
    }
};
node*trie;
void insert (int num){
    node*it=trie;
    for(int i=31;i>=0;i--){
        int curr_bit=(num>>i)&1;
        if(!it->next[curr_bit]){
            it->next[curr_bit]=new node();
        }
        it=it->next[curr_bit];
    }
    
}
int query(int num){
    node*it=trie;
    int ans=0;
    for(int i=31;i>=0;i--){
        int curr_bit=(num>>i)&1;
        int opposite=curr_bit^1;
        if(it->next[opposite]){
            it=it->next[opposite];
            ans|=1<<i;
        }
        else{
            it=it->next[opposite^1];

        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    trie=new node();
    insert(0);
    vi rmax(n+1,0);
    int R=0;
    for(int i=n-1;i>=0;i--){
        R= R^a[i];
        if(i!=n-1){
            rmax[i]=max(rmax[i+1],query(R));
            insert(R);
        }
        else{
            rmax[i]=query(R);
            insert(R);
        }
    }
    free(trie);
    trie=new node();
    insert(0);
    int ans=0;
    int L=0;
    rep(i,0,n){
        L=L^a[i];
        ans=max(ans, rmax[i+1]+query(L));
        insert(L);
    }
    cout<<ans;
}