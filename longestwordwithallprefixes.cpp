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

/*given a array of strings find the longest string in words such
that every prefix of it is also in words*/
struct Node{
    Node*arr[26];
    bool flag=0;
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
int insert(string word){
    Node*temp=root;
    int cnt=0;
    int n=word.size();
    rep(i,0,n){
        if(!temp->contains(word[i])){
            Node*newNode=new Node();
            temp->put(word[i], newNode);
        }
        if(temp->isflagset())cnt++;
        temp=temp->getnext(word[i]);
    }
    temp->setflag();
    return cnt;
}
string longestword(vector<string>&word){
    sort(all(word));
    string res="";
    int n=word.size();
    rep(i,0,n){
        int cnt=insert(word[i]);
        if(cnt==word[i].size()-1&&word[i].size()>res.size())res=word[i];
    }
    return res;
}