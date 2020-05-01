#include<bits/stdc++.h>

using namespace std;


int  sortt(int arr[],int s1,int e1);
void quick_sort(int arr[],int low,int high){
    if(low<high){
        int h=sortt(arr,low,high);
        quick_sort(arr,low,h-1);
        quick_sort(arr,h+1,high);
    }




}


int  sortt(int arr[],int low,int high){
    int n=arr[low];
    int j=low;
    for(int i=low+1;i<=high;i++){
            if(arr[i]<n){
                swap(arr[j],arr[i]);
                swap(arr[++j],arr[i]);
            }
        }
        return j;
}




int main()
{
    int arr[17]={2,9,8,3,1,66,7,8,8,99,99,12,14,12,1,12,33};
    quick_sort(arr,0,16);
    //printing array after sort
	for(int i=0;i<17;i++){
        cout<<arr[i]<<" ";
	}



}
