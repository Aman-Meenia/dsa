#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;


int n , m;
int dp[1010][20];

int fun(vector<vector<int>> & v , int index , int pre){

if(index>=m){
    return 0;
}

int ans = INT_MAX;
if(dp[index][pre+1]!=-1) return dp[index][pre+1];

if(pre==-1){

for(int i=0; i<10; i++)
{
    int present = n-v[index][i];
 int   ans1= present+fun(v,index+1,i);
ans = min(ans,ans1);
}


}else{
    for(int i=0; i<10; i++){
        if(i==pre)continue;

          int present = n-v[index][i];
       int ans2 =  present +fun(v,index+1,i);
       ans = min(ans,ans2);
    }
}
return dp[index][pre+1]=ans;

}






int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


// int n , m;
cin >> n >> m;
vector<vector<int>> v(n,vector<int>(m,0));
for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        cin>>v[i][j];
    }
}
memset(dp,-1,sizeof dp);

vector<vector<int>> t;
for(int i=0; i<m; i++){
    vector<int> dp(10);
    for(int j=0; j<n; j++){
dp[v[j][i]]+=1;
    }
    // for(auto it:dp)cout<<it<<" ";cout<<endl;
        t.push_back(dp);
}



cout<<fun(t,0,-1)<<endl;

cout<<fixed<<pow(4,10)<<endl;





}
