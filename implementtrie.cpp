#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define vli vector<ll>
#define vvi vector<vi>
#define vvli vector<vli>
#define pii pair<int, int>
#define pli pair<ll, ll>
#define vii vector<pii>
#define vll vector<pli>
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define vb vector<bool>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i,a,b) for(int i=a;i>b;i--);
#define M 1000000007
#define all(x) (x).begin(),(x).end()
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

/*
https://ideone.com/JJqYYp
https://www.geeksforgeeks.org/minimum-xor-value-pair/
https://www.geeksforgeeks.org/find-the-maximum-subarray-xor-in-a-given-array/

*/
struct Node{
    Node*arr[26];
    bool flag=false;
    bool contains(char c){
        return (arr[c-'a']!=NULL);
    }
    void put(char c, Node*newNode){
        arr[c-'a']=newNode;
    }
    Node*getnext(char ch){
        return arr[ch-'a'];
    }
    void setflag(){
        flag=1;
    }
    bool isflagset(){
        return flag;
    }
};
Node*root=new Node();
void insert(string word){
    Node*temp=root;
    int n=word.size();
    rep(i,0,n){
        if(!temp->contains(word[i])){
            Node*newNode=new Node();
            temp->put(word[i], newNode);
        }
        temp=temp->getnext(word[i]);
    }
    temp->setflag();
}
bool search(string word){
    Node*temp=root;
    int n=word.size();
    rep(i,0,n){
        if(temp->contains(word[i])){
            temp=temp->getnext(word[i]);
        }
        else return false;
    }
    return temp->isflagset();
}
/*return 1 if there is a previously 
inserted string word that has the prefix
and false otherwise*/
bool startswith(string word){
    Node*temp=root;
    int n=word.size();
    rep(i,0,n){
        if(temp->contains(word[i])){
            temp=temp->getnext(word[i]);
        }
        else return false;
    }
    return 1;
}
