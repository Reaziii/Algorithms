/*
  Bismillahir Rahmanir Raheem

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

mgraph graph;


void data(int k){
    fri(k){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);

   }
}

void bfs(int root,int n){
    queue <pii> q;
    pii x;

    q.push(mp(root,0));
    int vis[100000];
    reset(vis,-1);

    while(!q.empty()){
        x = q.front();
        q.pop();

        if(vis[x.first]==-1){
            vis[x.first]=x.second;

            fri(graph[x.first].size()){
                q.push(mp(graph[x.first][i],x.second+1));


            }


        }


    }

    for(int i=1;i<=n;i++){
        cout<<vis[i]<<" ";

    }
    pn;






}



int main(){
    int n;
    int k;
    cin>>n>>k;
    data(k);
    int root = 1;
    bfs(root,n);
}


/*
Input :
5 5
1 2
2 3
3 4
4 5
1 5
*/



