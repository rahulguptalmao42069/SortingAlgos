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


void BubSort(int a[],int n){
    for(int pass=1;pass<=n-1;pass++){
        int flag=0;
        for(int j=0;j<n-pass;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag++;
            }
        }
        if(flag==0)
            return;
    }
}

//WOST: n*n AVG n*n BEST n(adaptive)
//InPlace 
//Stable
//Selection sort is better than this as no. of swaps is less

void InsSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int value=arr[i];
        int hole=i;
        while(hole>0 && arr[hole-1]>value){
            arr[hole]=arr[hole-1];
            hole--;
        }
        arr[hole]=value;
    }
}

//WOST: n*n AVG n*n BEST n(adaptive)
//InPlace 
//Stable
//Best so far it has very less shifts and comparisions hence used often in LL

void ShellSort(int* A,int n){
    for(int gap=n/2;gap>=1;gap/=2){
        for(int i=gap;i<n;i++){
            int key=A[i];
            int hole=i-(gap-1);
            while(hole>0 && A[hole-1]>key){
                A[hole+gap-1]=A[hole-1];
                hole=hole-gap;
            }
            A[hole+gap-1]=key;
        }
    }
}

//ALL O(nlogn) (adaptive)
//InPlace 
//Stable
//depending upon how we're taking gap, time complexity can change
//useful for sorting v.large arrays

void Merge(int *A,int *L,int *R,int nl,int nr){
    int i=0,j=0,k=0;
    while(i<nl && j<nr){
        if(L[i]<=R[j])
            A[k++]=L[i++];
        else
            A[k++]=R[j++];
    }

    while(i<nl)
        A[k++]=L[i++];
    while(j<nr) 
        A[k++]=R[j++];
}

void MergeSort(int *A,int n){
    if(n<2)
        return;
    int mid=n/2;

    //int L[mid];
    //int R[n-mid]; //This is bad way as we cannot delete this static array.

    //int *L=(int*)malloc(mid*sizeof(int));
    //int *R=(int*)malloc((n-mid)*sizeof(int));

    int *L= new int[mid];
    int *R= new int[n-mid];

    for(int i=0;i<mid;i++)
        L[i]=A[i];
    for(int i=mid;i<n;i++)
        R[i-mid]=A[i];
    MergeSort(L,mid);
    MergeSort(R,n-mid);
    Merge(A,L,R,mid,n-mid);
    free(L);
    delete R;
}

//ALL O(nlogn)
//n
//Stable
//Only comparision sort that is NOT Inplace

int parti(int A[],int s,int e){
    swap(A[rand() %(e - s + 1) + s],A[e]);
    int pivot=A[e];
    int pindx=s;
    for(int i=s;i<=e;i++){
        if(A[i]<=pivot)
            swap(A[i],A[pindx++]);
    }
    return --pindx;
}

void QuickSort(int *A,int s,int e){
    if(s>=e)
        return;
    int pindx=parti(A,s,e);
    QuickSort(A,s,pindx-1);
    QuickSort(A,pindx+1,e);
}

//WOST: n*n AVG: nlogn BEST nlogn
//logn approx 1 aka Inplace
//Unstable
//Most prebuilt sorting algos uses this

void heapify(int* A, int n, int i){
    //O(logn)
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    while(left<n && A[left]>A[largest]){
        largest=left;
    }
    while(right<n && A[right]>A[largest]){
        largest=right;
    }

    if(largest!=i){
        swap(A[largest],A[i]);
        heapify(A,n,largest);
    }
}

void HeapSort(int* A,int n){
    // Leaf nodes will not have a child,
    // leaf nodes start from [n/2] to n-1
    // so largest non leaf node is [n/2]-1
    //Heapify process can be applied to a node only if its children are heapified.
    //So the heapification must be performed in the bottom-up order.
    
    //Buidling heap avoiding leaf nodes
    for(int i=n/2-1;i>=0;i--){
        heapify(A,n,i);
    }

    //Deleting root node(largest) and swapping with last element(smallest)
    //then heapifying the rest of tree of size i starting from node 0
    for(int i=n-1;i>=0;i--){
        swap(A[0],A[i]);
        heapify(A,i,0);
    }
}

//ALL O(nlogn)
//InPlace 
//Unstable
//Similar to Selection sort

void CountSort(int* A,int n){
    int mini=A[0],maxi=A[0];
    for(int i=0;i<n;i++){
        if(A[i]>maxi)
            maxi=A[i];
        if(A[i]<mini)
            mini=A[i];
    }
    mini=0;

    int range=maxi-mini+1;
    int hash[range];
    for(int i=0;i<range;i++)
        hash[i]=0;  

    for(int i=0;i<n;i++)
        hash[A[i]-mini]++;

    int k=0;
    for(int i=0;i<range;i++)
        if(hash[i]!=0){
            int cnt=hash[i];
            A[k++]=i+mini;
            cnt--;
        }
}
//Time: O(n + r)
//Space O(n + r )
//Stable
//We use hashing here
//Non comparision based (index based)

int quicksel(int* A,int i, int j, int k){
    if(i==j){
        if(i==k)
            return A[i];
        return INT_MIN;
    }

    int r=parti(A,i,j);
    if(r==k)
        return A[r];
    if(r>k)
        return quicksel(A,i,r-1,k);
    return quicksel(A,r+1,j,k);
}

//WOST: n*n AVG n BEST n
//Only No. of recursive called is changed

int binsearch(int *A,int s,int e,int k){
    if(e>=s){
        int mid=s + (e-s)/2;

    if(k<A[mid])
        return binsearch(A,s,mid-1,k);
    if(k>A[mid])
        return binsearch(A,mid+1,e,k);
    if(k==A[mid])
        return mid;
    }
    return -1;
}

//O(logn) provided array is already sorted

int main(){
    int arr[]={3,2,1,8};
    int n=sizeof(arr)/sizeof(arr[2]);
    int k=4;
    cout<<quicksel(arr,0,n-1,3);
}