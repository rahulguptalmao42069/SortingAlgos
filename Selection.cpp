#include<bits/stdc++.h>
using namespace std;

void SelSort(int A[],int n){
    for(int i=0;i<n-1;i++){
        int i_min=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[i_min])
                i_min=j;
        }
        swap(A[i_min],A[i]);
    }
}

//ALL O(n^2)
//InPlace
//Unstable
//Has minimum no. of swaps 

int main(){
    int arr[]={3,2,1,8};
    int n=sizeof(arr)/sizeof(arr[2]);
    SelSort(arr,n);

    for(int &n:arr) cout<<n<<" ";
}