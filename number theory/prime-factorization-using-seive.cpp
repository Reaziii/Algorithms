  
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



const int mx = 100000;

int arr[mx];


void seive_for_prime_factorization()
{
	clr(arr);
	arr[1] = 1;
	for(int i=2;i<=mx;i++){
		if(arr[i]==0){
			for(int j=i;j<=mx;j+=i){
				if(arr[j]==0){
					arr[j]=i;
				}
			}
		}
	}

}



vector<int> fact(int n ){
	vector<int> v;


	while(n>1){
		int x = arr[n];
		v.pb(x);
		n/=x;
	}
	return v;
}

int main(){
	// output;
	seive_for_prime_factorization();
	int n = 105;
	vector<int> v = fact(n);
	for(auto x : v ) cout<<x<<" ";
}
