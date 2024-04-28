#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


struct node{

ll val ;
ll lazy;

node(){
    val = 0;
    lazy=0;
}


};


node t[4*200100];

// merge

// lazy
void push (int id,int l , int r){
if(l!=r){
    t[2*id].lazy+=t[id].lazy;
        t[2*id+1].lazy+=t[id].lazy;
}
t[id].val+=t[id].lazy;
t[id].lazy=0;

}



// build
void build(int id , int l , int r , vector<int>&v){

if(l==r){
    t[id].val=v[l];
    return ;
}

int mid = l +(r-l)/2;

build(2*id,l,mid,v);
build(2*id+1,mid+1,r,v);


}

// update 

void update(int id , int l , int r, int lq , int rq ,int val ){
push(id,l,r);

if(lq>r|| rq<l){
    return ;
}
if(l>=lq && r<=rq){
    t[id].lazy+=val;
    push(id,l,r);
    return ;
}

int mid = l+ (r-l)/2;
update(2*id,l,mid,lq,rq,val);
update(2*id+1,mid+1,r,lq,rq,val);


}


// get query
ll get_query(int id ,int l , int r , int lq , int rq ){
push(id,l,r);
if(lq>r || rq<l){
    return 0;
}

if(l>=lq && r<=rq){

return t[id].val+t[id].lazy;
}

int mid = l +(r-l)/2;

ll a=get_query(2*id,l,mid,lq,rq);
ll b=get_query(2*id+1,mid+1,r,lq,rq);
return a+b;
}



int main(){
#ifndef ONLINE_JUDGE
    // for getting input
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


int n ,k;
cin >> n >>k;

vector<int> v(n);

for(int i=0; i<n; i++){
    cin >>v[i];
}

build(1,0,n-1,v);

while(k--){

int a ;
cin >>a;


if(a==1){

    int lq , rq , val;
    cin >> lq >> rq >>val;
    lq--,rq--;
    // update 
update(1,0,n-1,lq,rq,val);

}else{
    int pos;
    cin >>pos;
    pos--;
    // get ans
    cout<<get_query(1,0,n-1,pos,pos)<<endl;


}



}



}