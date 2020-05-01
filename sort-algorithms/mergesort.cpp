#include<bits/stdc++.h>


using namespace std;
void merge_(int arr[],int s1,int e2);


int arr3[20];


void merge_sort(int arr[],int s,int e){
    int n=(s+e)/2;
    if(e>s){
        merge_sort(arr,s,n);
        merge_sort(arr,n+1,e);
        merge_(arr,s,e);
    }
}




void merge_(int arr[],int s1,int e2){
    int k=0;

    int e1=(s1+e2)/2;
    int s2=e1+1;

    for(int i=s1,j=s2;k<=s1+e2;){
        if(i==e1+1){
            arr3[k++]=arr[j++];
        }
        else if(j==e2+1){
            arr3[k++]=arr[i++];
        }
        else if(arr[i]<arr[j]){
            arr3[k++]=arr[i];
            i++;
        }
        else if(arr[i]>=arr[j]){
            arr3[k++]=arr[j++];
        }
    }
    k=e2;
    for(int i=s1,j=0;i<=k;i++,j++){
        arr[i]=arr3[j];
    }


}




int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    int arr[n];

    int arr4[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr4[i]=arr[i];
    }
    merge_sort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    sort(arr4,arr4+n);

    for(int i=0;i<n;i++){
        cout<<arr4[i]<<" ";
    }



}
