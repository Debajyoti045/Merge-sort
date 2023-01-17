#include <iostream>
using namespace std;
void merge(int*arr,int st,int e){
    int mid = st + (e-st)/2;
    int len1 = mid - st + 1;
    int len2 = e - mid;
    //creating two arrays
    int *first = new int[len1];
    int *second = new int[len2];
    int mainindex = st;
    //copying values in the two arrays
    for(int i=0;i<len1;i++){
       first[i] = arr[ mainindex++];
    }
    mainindex = mid + 1;
    for(int j=0;j<len2;j++){
       second[j] = arr[ mainindex++];
    }
    //merge two sorted arrays
    mainindex = st;
    int i = 0;
    int j = 0;
    while(i<len1 && j<len2){
        if(first[i]<second[j]){
            arr[mainindex++] = first[i++];
        }
        else{
          arr[mainindex++] = second[j++];  
        }
    }
    while(i<len1){
         arr[mainindex++] = first[i++];
    }
    while(j<len2){
        arr[mainindex++] = second[j++];  
    }
}
void mergesort(int *arr,int st,int e){
    if(st>=e){
        return;
    }
    int mid = st + (e-st)/2;
    mergesort(arr,st,mid);
    mergesort(arr,mid+1,e);
    merge(arr,st,e);
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}