#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<unordered_set> 
#include<math.h>
#include<algorithm>
#define py cout<<"Yes\n";
#define pn cout<<"No\n";

#define google(i) cout<<"Case #"<<i<<": ";
 
#define mod 1000000007
#define pi 3.141592653589793238
  
#define ll long long
#define ull unsigned long long  
#define pb push_back
#define fi first
#define bg begin();
#define en end();
#define se second 
#define mpp make_pair
#define F first
#define S second
 
#define fl(i,n) for(ll i=0;i<n;i++)
#define fll(i,start,end) for(ll i=start;i<end;i++)
#define rl(i,m,n) for(ll i=n;i>=m;i--)
#define all(v) v.begin(),v.end()
 
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define AmanMeenia cout.tie(NULL);
using namespace std;
 



 /************************ ------------------------------------------------------ ************************/

// DECIMAL TO BINARY 
string decimaltobinary(long long  n){
string s;
    while(n>0){
        int k=n%2;
        s.push_back(k+'0');
        n=n/2;
        
    }
    // while(s.size()<32){
    //     s.push_back('0');
    // }
reverse(s.begin(),s.end());
    return s;
}
 
 
// BINARY TO DECIMAL 
 
ll binarytodecimal(string &s){
    int size=s.size();
    ll ans=0;
    int k=0;
    for(int i=size-1; i>=0; i--){
int t=s[i]-'0';
ans=ans+(pow(2,k)*t);
k++;
    }
    return ans;
}
 
 

 //  GCD AND LCM 
 
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a*b/gcd(a,b));}


//  POWER OF NUMBER


int mpow(int a, int b){
    ll ans  = 1;
while(b>0){
    if(b%2==1){
        ans = (ans%mod * a%mod) % mod;
    }
a=((ll)a%mod * a%mod) % mod;
  b >>= 1;

}
return ans%mod;
}


 /************************ ------------------------------------------------------ ************************/
 
//  WRITE CODE HERE 

// prime number find 

set<ll> st;
set<ll> st2;
int maxi;
void sieve(ll n, ll a)
{
// cout<<" A "<<a<<endl;
    // vector<int>  prime(n+1,1);
cout<<" sieve start "<<endl;
    for (int k=a; k<=a; k++) {
        // if(prime[k] == 1) {
        cout<<" hakldsj. "<<endl;
            for (int i = k ; i <= n; i += k){

                st.insert(i);
        }
        // cout<<endl;
    }

cout<<" hi sive"<<endl;
}


vector<ll>  lcm_of_all_number (vector<int> & v){
vector<ll> ans;
// for(auto it:v)cout<<it<<" ";cout<<endl;
for(int i=0; i<v.size(); i++){

    for(int j=i+1; j<v.size(); j++){
ll temp = lcm(v[i],v[j]);
// cout<<" temp "<<temp<<endl;
ans.push_back(temp);
    }
}
cout<<" works "<<endl;
return ans;

}


int count_same_number(vector<int> & v , ll k ){
ll cnt = 0;
ll total = 0;
st2.clear();

for(auto val:v){
     cnt = 0;
for(auto it:st){

    if(it<=k && it%val==0){
        // cout<<it<<" va; "<<val<<endl;
        cnt++;
        st2.insert(it);
    }
}

// cout<<cnt<<endl;
total+=cnt;
}
return total;
}

ll total_number(vector<int> &temp , ll k){
    int ans =0;
    for(auto it:temp){
        ans+=(k/it);
    }
    return ans;

}

ll acutal_number(vector<int> & v , ll k){
    ll ans =0;

    for(int i=0; i<v.size(); i++){
        ans+=(k/v[i]);
    }
    return ans;
}


ll different_number(vector<int> & v,ll k){


vector<ll> temp= lcm_of_all_number(v);
// for(auto it:temp)cout<<it<<" ";cout<<endl;

for(auto it:temp){
sieve(k,it);
}
cout<<" hi "<<endl;
// ll total = total_number(temp,k);
ll total = count_same_number(v,k);
// cout<<" total "<<total<<endl;
ll actual = acutal_number(v,k);
// cout<<" acutal "<<actual<<endl;
// for(auto it:st)cout<<it<<" ";cout<<endl;

    return st2.size()+actual-total;
}






ll fun(vector<int> & v , int k ){
sort(v.begin(),v.end());
maxi = v.back();


    ll low = 0; 
    // ll high = ;
    ll high = 1000000;

    while(low<=high){

ll mid = low+(high-low)/2;
cout<<" mid "<<mid<<endl;
ll temp = different_number(v,mid);
cout<<mid <<" temp is "<<temp<<endl;
if(temp>=k){
    high=mid-1;
}else{
    low=mid+1;
}



    }

// cout<<" ANS "<<low<<endl;

return low;

}










 /************************ ------------------------------------------------------ ************************/
int  main( ){
    #ifndef ONLINE_JUDGE
    // for getting input 
    freopen("input1.txt","r",stdin);
    // for writing output
    freopen("output1.txt","w",stdout);
#endif
 
 int n ;
 cin >>n;

 vector<int>v(n,0);

 for(int i=0; i<n; i++) cin>>v[i];



// cout<<different_number(v,18)<<endl;

cout<<fun(v,4)<<endl;



// cout<<pow(2,15)<<end


 // cout<<100/lcmis<<endl;








}
 /************************ ------------------------------------------------------ ************************/

// priority_queue<pair<int,pair<int,int> > , vector<pair<int,pair<int,int> >>,greater<pair<int,pair<int,int> >> >pq;
 
// priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> >> >pq;

// priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> >,greater< pair<int,pair<int,int> >> pq;
