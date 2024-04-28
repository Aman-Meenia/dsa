#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;

    int n ,m;
    long long numberOfRightTriangles(vector<vector<int>>& v) {
        n = v.size();
        m = v[0].size();
        
        vector<vector<int>> left(n,vector<int>(m,0));
         vector<vector<int>> right(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                left[i][j]=v[i][j];
                if(j>0){
                    left[i][j]+=left[i][j-1];
                }
                
            }
        }
        
        for(int j=0; j<m; j++){
            for(int i=n-1; i>=0; i--){
                right[i][j]=v[i][j];
                if(i<(n-1)){
                    right[i][j]+=right[i+1][j];
                }
            }
        }


        for(auto it:left){
            for(auto a:it){
                cout<<a<<" ";
            }cout<<endl;
        }cout<<endl;


        for(auto it:right){
            for(auto a:it){
                cout<<a<<" ";
            }cout<<endl;
        }cout<<endl;



      ll ans =0;  
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j]==1 && left[i][m-1]>=2){
                    int a = left[i][m-1];
int b = right[0][j];
                    b-=1;
a-=1;
                    if(a>0 && b>0){
                        // if(a>=2){
                            cout<<" i "<<i<<" j "<<j<<endl;
                            cout<<"a "<<a<<" b "<<b<<endl;
                        ans +=(a*b);
                    // }
                    }
                }
            }
        }
        
        
        
        return ans;
        
    }





 
int main(){
#ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif


int n ,m;
cin >>n >>m;

vector<vector<int>>v(n,vector<int>(m,0));
for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        cin>>v[i][j];
    }
}

ll ans = numberOfRightTriangles(v);

cout<<ans<<endl;











}
