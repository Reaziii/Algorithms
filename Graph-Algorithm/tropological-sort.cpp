#include<bits/stdc++.h>
#define sc(x)        scanf("%lld",&x)
#define pcase(x)     printf("Case %d: ",x++)
#define pn           printf("\n")
#define fr(f)        for(int i=0;i<f;i++)
#define reset(x,e)   memset(x,e,sizeof(x))
#define input        freopen("input.txt","r",stdin);
#define output       freopen("output.txt","w",stdout)
#define infi         INT_MAX
#define max_value    6000
#define pii          pair<int,int>
#define pch          pair<char,char>
#define mgraph       map<int,vector<int> >
#define mp           make_pair
#define pb           push_back
#define clr(x)       memset(x,0,sizeof(x))

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;


 //....................Start from here....................//
//.......................................................//


mgraph graph;
vector<int> indegree(1000000,0);
vector<int> outdegree(1000000,0);

void take_data(int k){
    fr(k){
        int x,y;
        cin>>x>>y;
        indegree[y]++;
        outdegree[x]++;
        graph[x].pb(y);

    }



}


void ts(int n){
    vector <int> res;
    queue <int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);

        }
    }
    
    while(!q.empty()){
        int x = q.front();

        res.push_back(x);
        q.pop();


        fr(graph[x].size()){

            int y = graph[x][i];

            if(--indegree[y]==0){
                q.push(y);
                //indegree[y]--;
                cout<<y<<endl;

            }
        }

    }
    fr(res.size())cout<<res[i]<<" ";
}




int main(){
    input;
   // output;

    int cs=1;
    int cn=1;
    //cin>>cs;
    while(cs--){
        //start form here//
        int n,k;
        cin>>n>>k;
        take_data(k);
        ts(n);pn;
       


    }
}






