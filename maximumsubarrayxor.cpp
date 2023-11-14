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
#define rev(i,a,b) for(int i=a;i>b;i--)
#define M 1000000007
#define all(x) (x).begin(),(x).end()
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

/*gievn an array find the maximum subarray xor value int eh given array*/
struct Node{
    Node*arr[2];
    int val;
    bool contains(int bit_no){
        return arr[bit_no]!=NULL;
    }
    void put(int bitno, Node*newNode){
        arr[bitno]= newNode;
    }
    Node*getnext(int bitno){
        return arr[bitno];
    }
};
Node*root=new Node();
void insert(int num){
    Node*temp=root;
    rev(bit,31,-1){
        int bitval=num&(1<<bit);
        if(temp->contains(bitval))temp=temp->getnext(bitval);
        else {
            Node*newNODE=new Node();
            temp->put(bitval,newNODE);
            temp=temp->getnext(bitval);
        }
    }
    temp->val=num;
}
int findmaxxor(int num){
    Node*temp=root;
    rev(bit,31,-1){
        int bitval=num&(1<<bit);
        if(temp->contains(!bitval))temp=temp->getnext(!bitval);
        else if(temp->contains(bitval))temp=temp->getnext(bitval);
        else return INT_MIN;
    }
    return num^(temp->val);
}
int solve(int arr[], int n){
    int prefixxor=arr[0];
    insert(prefixxor);
    int maximumxor=prefixxor;
    rep(i,1,n){
        prefixxor=prefixxor^arr[i];
        maximumxor=max(maximumxor,prefixxor);
        maximumxor=max(maximumxor,findmaxxor(prefixxor));
    }
    return maximumxor;
}