 
/*
    Bismillahir Rahmanir Raheem
    Think Twice Code Once
    prime factorization using seive 
    ------------------------------
*/


#include<bits/stdc++.h>
#define sc(x)        scanf("%lld",&x)
#define pcase(x)     printf("Case %d: ",x++)
#define pn           printf("\n")
#define fri(f)       for(int i=0;i<f;i++)
#define frj(f)       for(int j=0;j<f;j++)
#define reset(x,e)   memset(x,e,sizeof(x))
#define all(x)       x.begin(),x.end()
#define input        freopen("input.txt","r",stdin);
#define output       freopen("output.txt","w",stdout)
#define infi         INT_MAX
#define max_value    3000000
#define pii          pair<int,int>
#define pch          pair<char,char>
#define pll          pair<ll,ll>
#define mgraph       map<int,vector<int> >
#define mp           make_pair
#define pb           push_back
#define clr(x)       memset(x,0,sizeof(x))

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;


 //.................___Start from here___.................//
//.................._____________________................//

int mx = 1000000;
int store[1000000];


void seive(){
	reset(store,-1);
	for(int i=2;i<=mx;i++){
		if(store[i]==-1){
			for(int j=i;j<=mx;j+=i){
				if(store[j]==-1) store[j]=i;
			}
		}
	}
}




int main(){
	seive();
	int x = 123456;
	vector<int> q;
	while(x!=1){
		q.pb(store[x]);
		x/=store[x];
	}
	int ans = 1;
	for(auto x : q){
		ans*=x;
		cout<<x<< " ";
	}
	cout<<endl<<ans<<endl;
}
