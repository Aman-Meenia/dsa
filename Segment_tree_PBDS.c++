#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;



struct node{
    int max_val;
  node(){
        max_val=0;

    }
};



// merge

node merge(node a , node b){
    node ans;
ans.max_val=min(a.max_val,b.max_val);
    return ans;
}

// build 
void build(int id , int l , int r , vector<int> &v, node t[]){

if(l==r){
    t[id].max_val=v[l];
    return ;
}

int mid = l + (r-l)/2;

build(2*id,l,mid,v,t);
build(2*id+1,mid+1,r,v,t);
t[id]=merge(t[2*id],t[2*id+1]);

}


// void update

void update(int id ,int l , int r , int lq, int rq , int val , node t[]){

if(lq>r||rq<l){
    return ;
}
if(l>=lq && r<=rq){
t[id].max_val=val;
return;
}
int mid = l+(r-l)/2;

update(2*id,l,mid,lq,rq,val,t);
update(2*id+1,mid+1,r,lq,rq,val,t);

t[id]=merge(t[2*id],t[2*id+1]);

}

// get query

int get_query(int id , int l , int r ,int val,node t[]){


if(t[id].max_val>val){
if(l==r) return 1;

if(t[id*2].max_val>val && t[id*2+1].max_val>val){

return r-l+1;
}
    int ans = 0;
int mid = l+(r-l)/2;
if(t[id*2].max_val>val){

 ans =ans+get_query(2*id,l,mid,val,t);
}

if(t[id*2+1].max_val>val){
    ans=ans+get_query(2*id+1,mid+1,r,val,t);
}

cout<<" Ans "<<ans<<endl;
return ans;
}

return 0;

}

int main(){
#ifndef ONLINE_JUDGE
    // for getting input
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif




int n;
cin >>n;
vector<int>v(n);

for(int i=0; i<n; i++){
    cin >>v[i];
}
node t1[4*100100];
node t2[4*100100];
build(1,0,n-1,v,t1);

cout<<get_query(1,0,n-1,3,t1)<<endl;


int t = 10;
cout<<t*(t+1)/2<<endl;


}
