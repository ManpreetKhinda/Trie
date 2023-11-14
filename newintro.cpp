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
#define MM INT_MAX
#define MN INT_MIN
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

/*
*/
struct Node{
    Node*arr[26];
    bool flag=false;
    bool contains(char c){
        return(arr[c-'a']!=NULL);
    }
    void put(char c, Node*newNode ){
        arr[c-'a']=newNode;
    }
    Node*getNext(char ch){
        return arr[ch-'a'];
    }
    void setFlag(){
        flag=1;
    }
    bool isFlagSet(){
        return flag;
    }
};
Node*root=new Node();
/*leetcode 1698*/
int distinctsubs(string s){
    int n=s.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        Node*temp=root;
        for(int j=i;j<n;j++){
            if(!temp->contains(s[j])){
                Node*newNode = new Node();
                temp->put(s[j],newNode);
                temp->setFlag();
                cnt++;
            }
            temp=temp->getNext();
        }
    }
    return cnt;
}
void insert(string word){
    Node*temp=root;
    for(int i=0;i<word.size();i++){
        if(!temp->contains(word[i])){
            Node*newNode=new Node();
            temp->put(word[i],newNode);
        }
        temp=temp->getNext(word[i]);
    }
    temp->setFlag();
}
bool search(string word){
    Node*temp=root;
    for(int i=0;i<word.size();i++){
        if(temp->contains(word[i])){
            temp=temp->getNext(word[i]);
        }
        else return false;

    }
    return temp->isFlagSet();
}
bool startsWith(string word){
    Node*temp=root;
    for(int i=0;i<word.size();i++){
        if(temp->contains(word[i])){
            temp=temp->getNext(word[i]);
        }
        else return false;
    }
    return 1;
}
/*find min xor*/
struct Node{
    Node*arr[2];
    int val;
    bool contains(int bit_no){
        return arr[bit_no]!= NULL;
    }
    void put(int  bitno, Node* newNode){
        arr[bitno]=newNode;
    }
    Node*getnext(int bitno){
        return arr[bitno];
    }
};
Node*root=new Node();
void insert(int num){
    Node*temp=root;
    for(int bit=31;bit>=0;bit--){
        int bitval=num&(1<<bit);
        if(temp->contains(bitval))temp=temp->getnext(bitval);
        else{
            temp->put(bitval,new Node());
            temp=temp->getnext(  bitval);
        }
    }
    temp->val=num;
    
}
int findminimumxor(int arr[], int n){
    int minxor=arr[0]^arr[1];
    insert(arr[0]);
    for(int i=1;i<n;i++){
        minxor=min(minxor,findminxor(arr[i]));
    }
    return minxor;
}
int findminxor(int num){
    Node*temp=root;
    for(int bit=31;bit>=0;bit--){
        int bitval=num&(1<<bit);
        if(temp->contains(bitval)){
            temp=temp->getnext(bitval);
        }
        else if(temp->contains(!bitval)){
            temp=temp->getnext(!bitval);
        }
        else return INT_MAX;
    }
    return num^(temp->val);
}
int findmaxxor(int num){
    Node*temp=root;
    for(int bit=31;bit>=0;bit--){
        int bitval=num&(1<<bit);
        if(temp->contains(!bitval)){
            temp=temp->getnext(!bitval);
        }
        else if(temp->contains(bitval)){
            temp=temp->getnext(bitval);
        }
        else return INT_MIN;
    }
    return num^(temp->val);
}
int findmaxXor(int arr[], int n){
    int prefixxor=arr[0];
    insert(prefixxor);
    int maximumxor=prefixxor;
    for(int i=1;i<n;i++){
        prefixxor=prefixxor^arr[i];
        maximumxor=max(maximumxor,prefixxor);
        maximumxor=max(maximumxor,findmaxxor(prefixxor));
    }
    return maximumxor;
}
/*leetcode 1707*/
bool comp(vector<int> v1, vector<int> v2){
    if(v1[1]<v2[1])return 1;
    return 0;
}
vector<int> maximizexor(vector<int> &nums, vector<vector<int>>&queries){
    vector<vector<int>>query=queries;
    for(int i=0;i<queries.size();i++)query[i].push_back(i);
    sort(nums.begin(),nums.end());
    sort(query.begin(),query.end(),comp);
    vector<int> ans(queries.size(),0);
    int i=0;
    for(auto it:query){
        int num=it[1];
        while(i<nums.size()&&nums[i]<=num){
            insert(nums[i]);
            i++;
        }
        ans[it[2]]=findmaxxor(it[0]);
    }
    return ans;
}