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
#define all(x)      x.begin(),x.end()
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

char graph[100][100];
pii position;
int total_char;
void take_data(int n){
    total_char=0;
    fri(n+2){
        frj(n+2){
            if(i==0 || j==0 || i==n+1 || j==n+1) graph[i][j]='#';
            else cin>>graph[i][j];
        }
    }
}


int dijkstra(pii pos1,pii pos2){
    priority_queue <pii> q;
    q.push(pos1);
    int dist[100][100];
    clr(dist);
    pii x;
    while(!q.empty()){
        x=q.top();
        q.pop();
        int i=x.first;
        int j=x.second;
        if(graph[i][j+1]=='.'){
            if(dist[i][j+1]==0 || dist[i][j+1]>dist[i][j]+1){
                dist[i][j+1]=dist[i][j]+1;
                q.push(mp(i,j+1));
            }

        }
        if(graph[i][j-1]=='.'){
            if(dist[i][j-1]==0 || dist[i][j-1]>dist[i][j]+1){
                dist[i][j-1]=dist[i][j]+1;
                q.push(mp(i,j-1));

            }
        }
        if(graph[i-1][j]=='.'){
            if(dist[i-1][j]==0 || dist[i-1][j]>dist[i][j]+1){
                dist[i-1][j]=dist[i][j]+1;
                q.push(mp(i-1,j));

            }
        }
        if(graph[i+1][j]=='.'){
            if(dist[i+1][j]==0 || dist[i+1][j]>dist[i][j]+1){
                dist[i+1][j]=dist[i][j]+1;
                q.push(mp(i+1,j));

            }
        }
    }
    return dist[pos2.first][pos2.second];
}





int main(){
    input;

    int n;
    cin>>n;
    take_data(n);

    pii pos1=mp(1,1);
    pii pos2=mp(5,5);
    if(dijkstra(pos1,pos2))cout<<dijkstra(pos1,pos2);
    else cout<<"Impossible";
}

/*
input:
5
.#.#.
.#...
..###
#.###
.....

'#' is obstacle
'.' is road

output:
8


(2,1),(3,1),(3,2),(4,2),(5,2),(5,3),(5,4),(5,5)


*/
