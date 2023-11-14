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
/*function to be implemente
count words equalt to:- return the number of instances of the 
string word in the trie
count words starting with:- return the number of strings in the
trie that have the string prefix as a prefix
void erase erases the string word from the trie
*/
struct Node{
    Node*arr[26];
    int cntwordsend=0;
    int cntprefixes=0;
    bool contains(char c){
        return (arr[c-'a']!=NULL);
    }
    void put(char c, Node*newNode){
        arr[c-'a']=newNode;
    }
    Node*getnext(char ch){
        return arr[ch-'a'];
    }
    void increaseendwith(){
        cntwordsend++;
    }
    void increasecntprefixes(){
        cntprefixes++;
    }
    void decreasewordsendswith(){
        cntwordsend--;
    }
    void decreasecntprefixes(){
        cntprefixes--;
    }
    int gertcountwordsend(){
        return cntwordsend;
    }
    int getcntprefixes(){
        return cntprefixes;
    }
};
Node*root =new Node();
void insert(string word){
    Node*temp=root;
    int n=word.size();
    rep(i,0,n){
        if(!temp->contains(word[i])){
            Node*newNode=new Node();
            temp->put(word[i],newNode);
        }
        temp->increasecntprefixes();
        temp=temp->getnext(word[i]);
    }
    temp->increaseendwith();
}
int countwordsequalto(string word){
    Node*temp=root;
    int n=word.size();
    rep(i,0,n){
        if(temp->contains(word[i])){
            temp=temp->getnext(word[i]);
        }
        else return 0;
    }
    return temp->gertcountwordsend();
}
int starswith(string word){
    Node*temp=root;
    int n=word.size();
    rep(i,0,n){
        if(temp->contains(word[i]))temp=temp->getnext(word[i]);
        else return 0;
    }
    return temp->getcntprefixes();
}
bool search(string word){
    Node*temp=root;
    int n=word.size();
    rep(i,0,n){
        if(temp->contains(word[i]))temp=temp->getnext(word[i]);
        else return 0;
    }
    if(temp->cntwordsend>0)return 1;
    else return 0;
}
void erase(string word){
    Node*temp=root;
    if(search(word)==0)return ;
    int n=word.size();
    rep(i,0,n){
        temp->decreasecntprefixes();
        temp->getnext(word[i]);
    }
    temp->decreasewordsendswith();
}