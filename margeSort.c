#include<stdio.h>
void marge(int arr[],int left,int mid,int right){
    int i=left;
    int j=mid+1;
    int k=0;
    int temp[right-left+1];
    while (i<=mid && j<=right){

        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    while (i<=mid){
        temp[k]=arr[i];
        i++;
        k++;

    }
    while (j<=right){
        temp[k]=arr[j];
        j++;
        k++;
    }

    i=left;
    k=0;
    while(i<=right){
        arr[i]=temp[k];
        i++;
        k++;
    }
    
}
void margeSort(int arr[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;

        margeSort(arr,left,mid);
        margeSort(arr,mid+1,right);
        marge(arr,left,mid,right);
    }
}


int main()
{
    int arr[]={38, 27, 43, 3, 9, 82, 10};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Original Array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    margeSort(arr,0,n-1);

    printf("\nSorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}