#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;
#define  N 1000000


int Parent[N];
int Rank[N];

void make_set(int n ){
    for(int i=0; i<n; i++){
        Parent[i]=i;
        Rank[i]=0;
    }
}


int find_parent(int node){
    if(node==Parent[node]){
return node;
    }

    return Parent[node]=find_parent(Parent[node]);
}


void union_find(int u , int v){
    u = find_parent(u);
    v = find_parent(v);

    if(Rank[u]<Rank[v]){
        Parent[u]=v;
    }else if(Rank[v]<Rank[u]){
        Parent[v]=u;
    }else{
        Parent[v]=u;
        Rank[u]++;
    }
}


int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif




}
