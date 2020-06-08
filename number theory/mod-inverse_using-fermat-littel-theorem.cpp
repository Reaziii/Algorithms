  
/*
    Bismillahir Rahmanir Raheem
    Think Twice Code Once
    author : reaziii
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
#define m_v          3000000
#define pii          pair<int,int>
#define pch          pair<char,char>
#define pll          pair<ll,ll>
#define mgraph       map<int,vector<int> >
#define mp           make_pair
#define pb           push_back
#define clr(x)       memset(x,0,sizeof(x))
#define frx(x,y)     for(int x=0;x<y;x++)
#define deb(x)       cout<<x
#define ideb(i,x)    cout<<i<<" "<<x
#define F            first
#define S            second
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;


 //.................___Start from here___.................//
//.................._____________________................//



//fermets littel theorem
//it will not work if mod is not prime and also when n and mod is not co-prime
int mod_inverse(int n,int k,int mod){
	if(k==0) return 1;
	else if(k%2){
		return (n*mod_inverse(n,k-1,mod))%mod;
	}

	else {
		int x = (mod_inverse(n,k/2,mod))%mod;
		return (x*x)%mod;
	}
}

int main(){
	cout<<mod_inverse(5,7-2,7)<<endl;
}

