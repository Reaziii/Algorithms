/*
    ....::::Bismillahhir Rahmanir Rahim::::....

*/


#include<bits/stdc++.h>
#define sc(x) scanf("%lld",&x)
#define pcase(x) printf("Case %d:",x++)
#define pn printf("\n")
#define For(e,f,i) for(int i=e;i<f;i++)
#define reset(x,e) memset(x,e,sizeof(x))
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout)
#define infi INT_MAX
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
map<int,vector<int> > graph;
int cost[1000][1000];
int n,k;
int distances[1000];


void take_data(){
    for(int i=1;i<=k;i++){
        int x,y,z;
        cin>>x>>y>>z;
        graph[x].push_back(y);
        graph[y].push_back(x);

        cost[x][y]=z;
        cost[y][x]=z;

    }


}


void dijkstra(int t){
    distances[t]=0;
    queue <int> q;
    q.push(t);
    int x;

    while(!q.empty()){
        x = q.front();
        q.pop();
            for(int i=0;i<graph[x].size();i++){
                int y=graph[x][i];
                if(distances[y]>distances[x]+cost[x][y]){
                    distances[y]=distances[x]+cost[x][y];
                    q.push(y);


                }

            }


    }

}



int main(){
    input;
    output;
    int cs;
    int cn=1;

    cin>>cs;
    while(cs--){
        reset(cost,0);
        graph.clear();
        cin>>n>>k;
        take_data();
        int t;
        cin>>t;
        for(int i=1;i<=n;i++) distances[i]=infi;
        dijkstra(t);
        cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<i<<" : "<<distances[i]<<endl;
        }
        pn;
    }




}
